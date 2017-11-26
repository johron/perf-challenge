#pragma once
#include "ISolver.h"

namespace Perf {
	template <typename SolverType>
	class Registry {
		using SolverStorage = std::unordered_map<std::string, std::unique_ptr<SolverType>>;
	public:
		Registry() = default;
		~Registry() = default;

		void addParticipant(std::unique_ptr<SolverType> solver) { 
			mStorage[solver->GetName()] = std::move(solver);
		}

		const SolverStorage& GetEntries() const { 
			return mStorage;
		}

	private:
		SolverStorage mStorage;
	};
}