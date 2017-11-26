#include "participants/Participants.h"

#include "DataProvider.h"
#include "DataGenerator.h"
#include "TestRunner.h"
#include "ResultStorage.h"
#include "ResultPrinter.h"

#include "../../perf-challenge-lib/src/Registry.h"
#include "../../perf-challenge-lib/src/ISolver.h"

// ToDo:
// * Dummy/Naive solution


int main(int argc, char** argv) {
	using TimeType = std::chrono::milliseconds;
	using ReturnType = bool;
	using InputType = std::string;

	const auto registry = Perf::RegisterParticipants<Perf::ISolver<ReturnType, InputType>>();
	const auto testData = Perf::CreateTestDataProvider<Perf::TestData<ReturnType, InputType>>();
	const auto testRunner = std::make_unique<Perf::TestRunner<ReturnType, InputType, TimeType>>(registry->GetSolvers(), testData->GetData());

	const auto results = testRunner->Run();
	Perf::PrintResults<TimeType>(results);

	getchar();
	return 0;
}
