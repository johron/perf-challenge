#pragma once

namespace Perf {
	void GenerateData(uint32_t itemCount, bool containDuplicates, const std::string& filename) {
		
		std::vector<std::string> data;
		data.reserve(itemCount);

		std::srand(6842685);
		constexpr auto numberSpace = 26 * 26 * 26 * 1000;
		const auto startingIndex = (std::rand() * std::rand()) % (numberSpace - itemCount);

		for (uint32_t i=0; i < itemCount; ++i) {
			std::string str = "______\n";
			auto baseIndex = i + startingIndex;

			str[0] = 'A' + (baseIndex % (26 * 26 * 26 * 1000)) / (26 * 26 * 1000);
			str[1] = 'A' + (baseIndex % (26 * 26 * 1000)) / (26 * 1000);
			str[2] = 'A' + (baseIndex % (26 * 1000)) / 1000;
			str[3] = '0' + (baseIndex % 1000) / 100;
			str[4] = '0' + (baseIndex % 100) / 10;
			str[5] = '0' + (baseIndex % 10) / 1;

			data.push_back(str);
		}

		std::random_shuffle(data.begin(), data.end());

		std::fstream file;
		file.open(filename, std::fstream::out);
		
		for (const auto& item : data) {
			file << item;
		}

		file.close();
	}
}