#include "participants/Participants.h"

int main(int argc, char** argv) {
	const auto registry = Perf::RegisterParticipants();
	const auto entries = registry->GetEntries();

	const auto inputData = { "sample1.txt", "sample2.txt", "sample3.txt" };

	for (const auto& entry : entries) {
		for (const auto& current : inputData) {
			// entry->Solve(current);
		}
	}



	return 0;
}