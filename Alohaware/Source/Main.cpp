#include <iostream>
#include <chrono>
#include "Coordinator.hpp"
#include "Registry.hpp"
#include "Logger.hpp"

#pragma once


int main()
{
	Coordinator coordinator;
	coordinator.Initialize();
	Register(coordinator);

	float dt = 0.0f;

	coordinator.InitializeSystems();

	while (true)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		coordinator.UpdateSystems(dt);

		auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
	}

	coordinator.ShutdownSystems();

	return 0;
}
