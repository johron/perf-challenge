#pragma once

namespace Perf {
	template <typename ReturnType, typename InputType>
	class ISolver {
	public:
		ISolver() = default;
		virtual ~ISolver() = default;

		virtual ReturnType Solve(InputType&& data) = 0;
	};
}