#pragma once

#include "TimeUnit.h"
#include "ResultStorage.h"

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
			, mSolvers(solvers) 
			, mResults(std::make_shared<ResultStorage>()){ }

		std::shared_ptr<ResultStorage> Run() {
			for (uint32_t i=0; i < mSolvers.size(); ++i) {
				std::cout << "Participant: " << mSolvers[i]->GetName() << " (" << i+1 << "/" << mSolvers.size() << ")" << "\n";
				for (const auto& data : mTestData) {
					PerformSolve(data, mSolvers[i]);
				}
			}

			return mResults;
		}

	private:
		void PerformSolve(const TestDataType& data, std::shared_ptr<SolverType> solver) {
			const auto timedSolver = std::make_unique<Perf::TimedSolver<ReturnType, InputType, TimeType>>(solver);
			const auto result = timedSolver->Solve(data.mInput);
			if (result.first == data.mResult) {
				mResults->AddResult(solver->GetName(), static_cast<uint32_t>(result.second.count()));
				std::cout << " - " << data.mInput << " (success)\n";
			} else {
				mResults->Disqualify(solver->GetName());
				std::cout << " - " << data.mInput << " (disqualified)\n";
			}
		}

		std::vector<TestDataType> mTestData;
		std::vector<std::shared_ptr<SolverType>> mSolvers;
		std::shared_ptr<ResultStorage> mResults;
	};
}