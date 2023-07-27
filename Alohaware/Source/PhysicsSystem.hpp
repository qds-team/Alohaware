#include <iostream>
#include "System.hpp"

#pragma once

class PhysicsSystem : System
{
	public:
		void Initialize();

		virtual void Update(float dt);

		virtual void Shutdown();
};