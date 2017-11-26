#pragma once
#include "../../perf-challenge-lib/src/TestData.h"
#include "../../perf-challenge-lib/src/ITestDataProvider.h"

namespace Perf {
	using TestDataType = TestData<bool, std::string>;
	
	class SampleDataProvider : public ITestDataProvider<TestDataType> {
	public:
		virtual std::vector<TestDataType> GetData() const override {
			std::vector<TestDataType> data;

			data.push_back(TestData<bool, std::string>(false, "example_01.txt"));
			data.push_back(TestData<bool, std::string>(false, "example_02.txt"));
			data.push_back(TestData<bool, std::string>(true, "example_03.txt"));
	
			return std::move(data);
		}
	};
}