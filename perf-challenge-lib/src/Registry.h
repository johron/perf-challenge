#pragma once
#include "ISolver.h"

namespace Perf {
	template <typename SolverType>
	class Registry {
		using SolverStorage = std::vector<std::shared_ptr<SolverType>>;
	public:
		Registry() = default;
		~Registry() = default;

		void addParticipant(std::shared_ptr<SolverType> solver) { 
			mStorage.push_back(solver);
		}

		const SolverStorage& GetSolvers() const { 
			return mStorage;
		}

	private:
		SolverStorage mStorage;
	};
}