#include "Implementation.h"

#include "../../Timer.h"

// The START_TIMER and END_TIMER macros can be used if you want to make very precise timings in nanoseconds.

namespace reference_user {
	bool Implementation::Solve(const std::string& filename) {
		std::ifstream file(filename);

		std::string line;
		std::vector<std::string> allKnownLines;
		bool result = false;

		START_TIMER(while_loop);
		while (std::getline(file, line)) {
			if (std::find(allKnownLines.begin(), allKnownLines.end(), line) != allKnownLines.end()) {
				result = true;
				break;
			}
			allKnownLines.push_back(line);
		}
		END_TIMER(while_loop);

		file.close();
		return result;
	}
}
