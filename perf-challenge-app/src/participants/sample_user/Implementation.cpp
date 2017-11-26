#include "Implementation.h"

namespace sample_user {
	bool Implementation::Solve(const std::string& data) {
		std::ifstream file(data);

		std::string line;
		std::vector<std::string> fileData;
		while (std::getline(file, line)) {
			fileData.push_back(line);
			line.clear();
		}

		std::sort(fileData.begin(), fileData.end());

		for (size_t i=1; i < fileData.size(); ++i) {
			if (fileData[i] == fileData[i - 1]) {
				return true;
			}
		}
		
		file.close();
		return false;
	}

}
