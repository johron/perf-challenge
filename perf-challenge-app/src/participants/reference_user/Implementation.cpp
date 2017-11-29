#include "Implementation.h"

namespace reference_user {
	bool Implementation::Solve(const std::string& filename) {
		std::ifstream file(filename);

		std::string line;
		std::vector<std::string> allKnownLines;
		while (std::getline(file, line)) {
			for (auto current : allKnownLines) {
				if (current == line) {
					return true;
				}
			}

			allKnownLines.push_back(line);
			line.clear();
		}

		file.close();
		return false;
	}
}
