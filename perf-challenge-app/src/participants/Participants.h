// ====================================================
// THIS CODE IS GENERATED - PLEASE DO NOT MANUALLY EDIT
// ====================================================
#pragma once 
#include "../../../perf-challenge-lib/src/Registry.h"

#include "participants/johan_ronnkvist/Implementation.h"
#include "participants/sample_user/Implementation.h"

namespace Perf {
	template <typename SolverType>
	std::unique_ptr<Perf::Registry<SolverType>> RegisterParticipants() {
		auto registry = std::make_unique<Perf::Registry<SolverType>>();
		registry->addParticipant(std::make_unique<johan_ronnkvist::Implementation>());
		registry->addParticipant(std::make_unique<sample_user::Implementation>());
		return std::move(registry);
	}
}