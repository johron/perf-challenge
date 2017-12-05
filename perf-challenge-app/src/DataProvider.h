#pragma once
#include "SampleDataProvider.h"

namespace Perf {
	template <typename TestDataType>
	std::shared_ptr<ITestDataProvider<TestDataType>> CreateTestDataProvider() {
		return std::make_shared<RealDataProvider>();
	}
}