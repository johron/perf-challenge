#pragma once
#include "ISolver.h"

namespace Perf {
	class Registry {
	public:
		Registry() = default;
		~Registry() = default;

		void addParticipant(const std::string& name, std::unique_ptr<ISolver<bool, std::string>> solver) { }

		const std::vector<std::unique_ptr<ISolver<bool, std::string>>>& GetEntries() const { }
	};
}