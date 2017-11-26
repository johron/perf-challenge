#include "participants/Participants.h"

#include "TestData.h"
#include "TestRunner.h"

#include "../../perf-challenge-lib/src/Registry.h"
#include "../../perf-challenge-lib/src/ISolver.h"

int main(int argc, char** argv) {
	const auto registry = Perf::RegisterParticipants<Perf::ISolver<bool, std::string>>();
	const auto testData = Perf::CreateTestDataProvider<Perf::TestData<bool, std::string>>();
	const auto testRunner = std::make_unique<Perf::TestRunner<bool, std::string>>(registry->GetSolvers(), testData->GetData());

	testRunner->Run();
	return 0;
}