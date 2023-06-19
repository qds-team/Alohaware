#include <iostream>
#include <chrono>
#include "Coordinator.hpp"

#pragma once


int main()
{
	std::cout << "Hello World!" << std::endl;

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
