#include "participants/Participants.h"

#include "DataProvider.h"
#include "TestRunner.h"
#include "ResultStorage.h"
#include "ResultPrinter.h"

#include "../../perf-challenge-lib/src/Registry.h"
#include "../../perf-challenge-lib/src/ISolver.h"

// ToDo:
// * Generators for test data
// * Dummy/Naive solution


int main(int argc, char** argv) {
	using TimeType = std::chrono::milliseconds;

	const auto registry = Perf::RegisterParticipants<Perf::ISolver<bool, std::string>>();
	const auto testData = Perf::CreateTestDataProvider<Perf::TestData<bool, std::string>>();
	const auto testRunner = std::make_unique<Perf::TestRunner<bool, std::string, TimeType>>(registry->GetSolvers(), testData->GetData());

	const auto results = testRunner->Run();
	Perf::PrintResults<TimeType>(results);

	getchar();
	return 0;
}