// ===================================================
// THIS CODE IS GENERATED - PLEASE DO NOT EDIT BY HAND
// ===================================================
#pragma once 
#include "../../../perf-challenge-lib/src/Registry.h"

#include "participants/sample_user/Implementation.h"

namespace Perf {
	template <typename SolverType>
	std::unique_ptr<Perf::Registry<SolverType>> RegisterParticipants() {
		auto registry = std::make_unique<Perf::Registry<SolverType>>();
		registry->addParticipant(std::make_unique<sample_user::Implementation>());
		return std::move(registry);
	}
}