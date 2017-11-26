#pragma once
#include "ResultStorage.h"

namespace Perf {
	template <typename T>
	void PrintResults(std::shared_ptr<ResultStorage> storage) {
		const auto results = storage->GetResults();

		std::vector<std::pair<std::string, uint32_t>> validResults;
		std::vector<std::pair<std::string, uint32_t>> disqualified;

		for (const auto& result : results) {
			if (!storage->IsDisqualified(result.first)) {
				validResults.push_back(result);
			} else {
				disqualified.push_back(result);
			}
		}

		std::sort(validResults.begin(), validResults.end(), [](const std::pair<std::string, uint32_t>& lhs, const std::pair<std::string, uint32_t>& rhs) {
			return lhs.second < rhs.second;
		});

		std::cout << "\n\n===[ Performance challenge: Successful results (" << validResults.size() << "/" << results.size() << ") ]===\n";
		for (size_t i=0; i < validResults.size(); ++i) {
			std::cout << i+1 << "\t" << validResults[i].first << "\t\t" << validResults[i].second << TimeUnit<T>::Get() << "\n";
		}


		if (!disqualified.empty()) {
			std::cout << "\n\n===[ Performance challenge: Disqualified results (" << disqualified.size() << "/" << results.size() << ") ]===\n";
			for (const auto& entry : disqualified) {
				std::cout << "*\t" << entry.first << "\t\t" << "disqualified" << "\n";
			}
		}

	}
}