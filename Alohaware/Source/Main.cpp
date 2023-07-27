#include <iostream>
//#include <chrono>
#include "Coordinator.hpp"
#include "Registry.hpp"
#include "Logger.hpp"

#pragma once


int main()
{
	Coordinator coordinator;
	coordinator.Initialize();
	coordinator.RegisterComponent<Logger>();

	return 0;

	float dt = 0.0f;

	/*while (!quit)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
	}
	*/
}
