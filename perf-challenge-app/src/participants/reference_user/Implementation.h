#include "../../../../perf-challenge-lib/src/ISolver.h"

namespace reference_user {
	class Implementation : public Perf::Solver { 
	public:
		virtual std::string GetName() const override { return "reference user"; }
		virtual bool Solve(const std::string& filename) override;

	};
}