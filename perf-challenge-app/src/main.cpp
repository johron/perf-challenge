#include "participants/Participants.h"
#include "../../perf-challenge-lib/src/Registry.h"
#include "../../perf-challenge-lib/src/ISolver.h"

int main(int argc, char** argv) {
	const auto registry = Perf::RegisterParticipants<Perf::ISolver<bool, std::string>>();
	const auto& entries = registry->GetEntries();

	const auto inputData = { "sample1.txt", "sample2.txt", "sample3.txt" };

	for (const auto& entry : entries) {
		std::cout << "Starting test for user (" << entry.first << ")" << "\n";
		for (const auto& current : inputData) {
			entry.second->Solve(current);
			std::cout << " - " << current << " " << 22 << "ms" << std::endl;
		}
	}

	return 0;
}