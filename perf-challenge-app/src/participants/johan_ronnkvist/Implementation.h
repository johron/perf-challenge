#include "../../../../perf-challenge-lib/src/ISolver.h"

namespace johan_ronnkvist {
	class Implementation : public Perf::TGA_Solver { 
	public:
		virtual std::string GetName() const override { return "johan ronnkvist"; }
		virtual bool Solve(const std::string& data) override;
	};
}