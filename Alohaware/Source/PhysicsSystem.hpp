#include <iostream>
#include "System.hpp"

#pragma once

class PhysicsSystem : public System
{
	public:
		void Initialize();

		void Update(float dt);

		void Shutdown();
};