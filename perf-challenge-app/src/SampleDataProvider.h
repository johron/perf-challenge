#pragma once
#include "../../perf-challenge-lib/src/TestData.h"
#include "../../perf-challenge-lib/src/ITestDataProvider.h"

namespace Perf {
	using TestDataType = TestData<bool, std::string>;

	class SampleDataProvider : public ITestDataProvider<TestDataType> {
	public:
		virtual std::vector<TestDataType> GetData() const override {
			return {
				{ true, "data/sample_file_001.txt" }, 
				{ false, "data/sample_file_002.txt" },
				{ false, "data/sample_file_003.txt" },
				{ true, "data/sample_file_004.txt" },
				{ true, "data/sample_file_005.txt" },
				{ true, "data/sample_file_006.txt" },
				{ false, "data/sample_file_007.txt" },
				{ true, "data/sample_file_008.txt" },
				{ false, "data/sample_file_009.txt" },
				{ true, "data/sample_file_010.txt" }
			};
		}
	};
}











