#pragma once

namespace Perf {
	template <typename ReturnType, typename InputType>
	class ISolver {
	public:
		ISolver() = default;
		virtual ~ISolver() = default;

		virtual std::string GetName() const = 0;
		virtual ReturnType Solve(const InputType& data) = 0;
	};

	using Solver = ISolver<bool, std::string>;
}