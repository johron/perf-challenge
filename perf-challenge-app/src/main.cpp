#include "participants/Participants.h"

#include "DataProvider.h"
#include "DataGenerator.h"
#include "TestRunner.h"
#include "ResultStorage.h"
#include "ResultPrinter.h"

#include "../../perf-challenge-lib/src/Registry.h"
#include "../../perf-challenge-lib/src/ISolver.h"

void GenerateSampleData() {
	Perf::GenerateRandomized(1 << 13, true, "data/sample_file_001.txt");
	Perf::GenerateRandomized(1 << 14, false, "data/sample_file_002.txt");
	Perf::GenerateRandomized(1 << 15, false, "data/sample_file_003.txt");
	Perf::GenerateRandomized(1 << 16, true, "data/sample_file_004.txt");
	Perf::GenerateRandomized(1 << 17, true, "data/sample_file_005.txt");
	Perf::GenerateRandomized(1 << 18, true, "data/sample_file_006.txt");
	Perf::GenerateRandomized(1 << 19, false, "data/sample_file_007.txt");
	Perf::GenerateRandomized(1 << 20, true, "data/sample_file_008.txt");
	Perf::GenerateRandomized(1 << 21, false, "data/sample_file_009.txt");
	Perf::GenerateRandomized(1 << 22, true, "data/sample_file_010.txt");
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
	if (argc == 2 && strcmp(argv[1], "--generate") == 0) {
		GenerateSampleData();
	} else {
		RunRegisteredSolvers();
	}

	return 0;
}
