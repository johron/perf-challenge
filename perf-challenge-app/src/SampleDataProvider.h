#pragma once
#include "../../perf-challenge-lib/src/TestData.h"
#include "../../perf-challenge-lib/src/ITestDataProvider.h"

namespace Perf {
	using TestDataType = TestData<bool, std::string>;

	class SampleDataProvider : public ITestDataProvider<TestDataType> {
	public:
		virtual std::vector<TestDataType> GetData() const override {
			return { 
				{ false, "example_01.txt" },
				{ false, "example_02.txt" },
				{ true, "example_03.txt" }};
		}
	};
}