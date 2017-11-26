#include "../../../../perf-challenge-lib/src/ISolver.h"

namespace sample_user {
	class Implementation : public Perf::TGA_Solver { 
	public:
		virtual std::string GetName() const override { return "sample user"; }
		virtual bool Solve(const std::string& data) override;

	};
}