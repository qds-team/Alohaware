#include <iostream>
#include "System.hpp"

#pragma once

class CollisionSystem : public System
{
	public:
		void Initialize();

		void Update(float dt);

		void Shutdown();
};

