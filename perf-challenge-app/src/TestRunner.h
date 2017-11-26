#pragma once

#include "TimeUnit.h"
#include "../../perf-challenge-lib/src/TestData.h"
#include "../../perf-challenge-lib/src/TimedSolver.h"

namespace Perf {
	template <typename ReturnType, typename InputType, typename TimeType>
	class TestRunner {
		using TestDataType = TestData<ReturnType, InputType>;
		using SolverType = ISolver<ReturnType, InputType>;
	public:
		TestRunner(const std::vector<std::shared_ptr<SolverType>>& solvers, const std::vector<TestDataType>& testData)
			: mTestData(testData)
			, mSolvers(solvers) { }

		void Run() {
			for (const auto& solver : mSolvers) {
				for (const auto& data : mTestData) {
					PerformSolve(data, solver);
				}
			}
		}

	private:
		void PerformSolve(const TestDataType& data, std::shared_ptr<SolverType> solver) {
			const auto timedSolver = std::make_unique<Perf::TimedSolver<ReturnType, InputType, TimeType>>(solver);
			const auto result = timedSolver->Solve(data.mInput);
			if (result.first == data.mResult) {
				std::cout << "success (" << result.second.count() <<  TimeUnit<TimeType>::Get() << ")\n";
				// valid result
			} else {
				std::cout << "fail (" << result.second.count() << TimeUnit<TimeType>::Get() << ")\n";
				// disqualify user;
			}
		}

		std::vector<TestDataType> mTestData;
		std::vector<std::shared_ptr<SolverType>> mSolvers;
	};
}