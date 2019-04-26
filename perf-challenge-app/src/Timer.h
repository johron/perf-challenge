#pragma once

#include <chrono>
#include <iostream>

#define START_TIMER(ID) const auto timer_##ID = std::chrono::high_resolution_clock::now();
#define END_TIMER(ID) printf("Timer " #ID " took: %uns\n", static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - timer_##ID).count()));
