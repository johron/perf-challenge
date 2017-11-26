#pragma once
#include "ISolver.h"

namespace Perf {
	template <typename ReturnType, typename InputType, typename TimeType>
	class TimedSolver : public ISolver <std::pair<ReturnType, TimeType>, InputType> {
	public:
		TimedSolver(std::shared_ptr<ISolver<ReturnType, InputType>> solver)
			: mSolver(solver) { }

		virtual std::string GetName() const override {
			return mSolver->GetName();
		}

		virtual std::pair<ReturnType, TimeType> Solve(const InputType& data) override {
			const auto begin = std::chrono::high_resolution_clock::now();
			const auto result = mSolver->Solve(data);
			const auto end = std::chrono::high_resolution_clock::now();
			const auto duration = std::chrono::duration_cast<TimeType>(end - begin);
			return std::make_pair(result, duration);
		}

	private:
		std::shared_ptr<ISolver<ReturnType, InputType>> mSolver;
	};
}