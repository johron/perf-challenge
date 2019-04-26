#pragma once
#include <assert.h>

#include <random>
#include <algorithm>

namespace Perf {
	void WriteFile(const std::vector<std::string>& items, const std::string& filename) {
		FILE* fp = NULL;
		fp = fopen(filename.c_str(), "wb");

		char newline[2] = { 0x0d, 0x0a };

		for (const auto& item : items) {
			fwrite(item.c_str(), 6, 1, fp);
			fwrite(newline, 2, 1, fp);
		}

		fclose(fp);
	}

	// This code was just used to generate example data, don't assume the real 
	// datasets will have this structure. 
	void InsertDuplicate(std::vector<std::string>& dataOut) {
		assert(dataOut.size() > 1);
		const auto offsetRange = std::max(static_cast<int>(dataOut.size() * 0.15f), 1);
		const auto indexBegin = std::rand() % offsetRange;
		const auto indexEnd = dataOut.size() - 1 - indexBegin;
		assert(indexBegin != indexEnd);
		dataOut[indexBegin] = dataOut[indexEnd];
	}

	void GenerateSequential(uint32_t itemCount, bool containDuplicates, const std::string& filename) {
		std::cout << "Generating sequential data: " << filename << " (" << itemCount << ")\n";
		std::vector<std::string> data;
		data.reserve(itemCount);

		std::srand(6842685);
		constexpr auto numberSpace = 26 * 26 * 26 * 1000;
		const auto startingIndex = (std::rand() * std::rand()) % (numberSpace - itemCount);

		for (uint32_t i=0; i < itemCount; ++i) {
			std::string str = "______";
			auto baseIndex = i + startingIndex;

			str[0] = 'A' + (baseIndex % (26 * 26 * 26 * 1000)) / (26 * 26 * 1000);
			str[1] = 'A' + (baseIndex % (26 * 26 * 1000)) / (26 * 1000);
			str[2] = 'A' + (baseIndex % (26 * 1000)) / 1000;
			str[3] = '0' + (baseIndex % 1000) / 100;
			str[4] = '0' + (baseIndex % 100) / 10;
			str[5] = '0' + (baseIndex % 10) / 1;

			data.push_back(str);
		}

		if (containDuplicates) {
			InsertDuplicate(data);
		}

		std::random_device rd;
		std::mt19937 g(rd());

		std::shuffle(data.begin(), data.end(), g);

		WriteFile(data, filename);
	}

	void GenerateRandomized(uint32_t itemCount, bool containDuplicates, const std::string& filename) {
		std::cout << "Generating randomized data: " << filename << " (" << itemCount << ")\n";
		std::unordered_set<std::string> data;

		data.reserve(itemCount);

		auto remaining = itemCount;
		while (remaining > 0) {
			std::string str = "______";
			str[0] = 'A' + std::rand() % 26;
			str[1] = 'A' + std::rand() % 26;
			str[2] = 'A' + std::rand() % 26;
			str[3] = '0' + std::rand() % 10;
			str[4] = '0' + std::rand() % 10;
			str[5] = '0' + std::rand() % 10;
		
			if (data.insert(str).second) {
				--remaining;
			}
		}

		std::vector<std::string> orderedData(data.begin(), data.end());
		if (containDuplicates) {
			InsertDuplicate(orderedData);
		}

		WriteFile(orderedData, filename);
	}
}