#pragma once

namespace Perf {
	template <typename ReturnType, typename InputType>
	class TestData {
	public:
		TestData(const ReturnType& correctResult, const InputType& input)
			: mInput(input), mResult(correctResult) { }
		~TestData() = default;

		const InputType mInput;
		const ReturnType mResult;
	};
}