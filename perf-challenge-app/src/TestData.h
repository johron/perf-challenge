#pragma once
#include "TestData_Sample_01.h"

namespace Perf {
	template <typename TestDataType>
	std::shared_ptr<ITestDataProvider<TestDataType>> CreateTestDataProvider() {
		return std::make_shared<SampleDataProvider>();
	}
}