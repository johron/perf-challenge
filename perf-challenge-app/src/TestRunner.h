#pragma once
#include "../../perf-challenge-lib/src/TestData.h"
#include "../../perf-challenge-lib/src/ISolver.h"

namespace Perf {
	template <typename ReturnType, typename InputType>
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
			const auto result = solver->Solve(data.mInput);
			if (result == data.mResult) {
				std::cout << "success" << "\n";
				// valid result
			} else {
				std::cout << "fail" << "\n";
				// disqualify user;
			}
		}

		std::vector<TestDataType> mTestData;
		std::vector<std::shared_ptr<SolverType>> mSolvers;
	};
}