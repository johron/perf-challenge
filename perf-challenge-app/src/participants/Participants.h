// ====================================================
// THIS CODE IS GENERATED - PLEASE DO NOT MANUALLY EDIT
// ====================================================
#pragma once 
#include "../../../perf-challenge-lib/src/Registry.h"

#include "participants/johan_ronnkvist/Implementation.h"
#include "participants/sample_user/Implementation.h"

namespace Perf {
	std::unique_ptr<Perf::Registry> RegisterParticipants() {
		auto registry = std::make_unique<Perf::Registry>();
		registry->addParticipant("johan_ronnkvist", std::make_unique<johan_ronnkvist::Implementation>());
		registry->addParticipant("sample_user", std::make_unique<sample_user::Implementation>());
		return std::move(registry);
	}
}