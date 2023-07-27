/*!
 * @author		Rishabh Anand
 * @brief		System Definition
!*/


#pragma once

#include <set>
#include "Entity.hpp"


class System
{
	public:
		std::set<Entity> entities;

		virtual void Initialize() {};

		virtual void Update(float dt) {};

		virtual void Shutdown() {};
};
