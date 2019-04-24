#include "participants/Participants.h"

#include "DataProvider.h"
#include "DataGenerator.h"
#include "TestRunner.h"
#include "ResultStorage.h"
#include "ResultPrinter.h"

#include "../../perf-challenge-lib/src/Registry.h"
#include "../../perf-challenge-lib/src/ISolver.h"

void GenerateSampleData() {
	// 128k files
	for (int i=0; i < 32; ++i) { 
		Perf::GenerateRandomized(1 << 14, i % 2 == 0, "data/small_files/file_" + std::to_string(i) + ".txt");
	}

	// 8mb files
	for (int i=0; i < 16; ++i) {
		Perf::GenerateRandomized(1 << 20, i % 2 == 0, "data/medium_files/file_" + std::to_string(i) + ".txt");
	}

	// 32mb files
	for (int i=0; i < 8; ++i) {
		Perf::GenerateRandomized(1 << 22, i % 2 == 0, "data/large_files/file_" + std::to_string(i) + ".txt");
	}
}

void RunRegisteredSolvers() {
	using TimeType = std::chrono::milliseconds;
	using ReturnType = bool;
	using InputType = std::string;

	const auto registry = Perf::RegisterParticipants<Perf::ISolver<ReturnType, InputType>>();
	const auto testData = Perf::CreateTestDataProvider<Perf::TestData<ReturnType, InputType>>();
	const auto testRunner = std::make_unique<Perf::TestRunner<ReturnType, InputType, TimeType>>(registry->GetSolvers(), testData->GetData());

	const auto results = testRunner->Run();
	Perf::PrintResults<TimeType>(results);
}

int main(int argc, char** argv) {
#ifdef NDEBUG
	if (!std::filesystem::exists("data/"))
		GenerateSampleData();
	else
#endif
		RunRegisteredSolvers();

	return 0;
}
