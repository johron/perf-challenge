#pragma once

namespace Perf {
	template <typename T>
	struct TimeUnit { static inline const char* Get() { return "undefined"; } };

	template <>
	struct TimeUnit<std::chrono::minutes> { static inline const char* Get() { return "min"; }; };

	template <>
	struct TimeUnit<std::chrono::seconds> { static inline const char* Get() { return "s"; }; };

	template <>
	struct TimeUnit<std::chrono::milliseconds> { static inline const char* Get() { return "ms"; }; };

	template <>
	struct TimeUnit<std::chrono::microseconds> { static inline const char* Get() { return "us"; }; };

	template <>
	struct TimeUnit<std::chrono::nanoseconds> { static inline const char* Get() { return "ns"; }; };
}