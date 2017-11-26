#pragma once

namespace Perf {
	class ResultStorage {
	public:
		ResultStorage() = default;
		~ResultStorage() = default;

		void AddResult(const std::string& name, uint32_t duration) {
			const auto iterator = mResults.find(name);
			if (iterator == mResults.end()) {
				mResults[name] = duration;
			} else {
				iterator->second += duration;
			}
		}

		void Disqualify(const std::string& name) {
			mDisqualifications.insert(name);
		}

		bool IsDisqualified(const std::string& name) const {
			return mDisqualifications.find(name) != mDisqualifications.end();
		}

		const std::unordered_map<std::string, uint32_t>& GetResults() const {
			return mResults;
		}

	private:
		std::unordered_map<std::string, uint32_t> mResults;
		std::unordered_set<std::string> mDisqualifications;
	};

}