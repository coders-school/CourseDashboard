#pragma once

#include <thread>
#include <chrono>
#include <cstdlib>

inline void postponedConsoleClear(std::chrono::seconds delay)
{
	std::this_thread::sleep_for(delay);
	std::system("clear");
}