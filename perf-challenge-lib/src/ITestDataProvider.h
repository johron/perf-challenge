#pragma once

namespace Perf {
	template <typename DataType>
	class ITestDataProvider {
	public:
		ITestDataProvider() = default;
		~ITestDataProvider() = default;

		virtual std::vector<DataType> GetData() const = 0;
	};
}