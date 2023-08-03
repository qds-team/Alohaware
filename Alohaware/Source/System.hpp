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

		virtual void Initialize() = 0;

		virtual void Update(float dt) = 0;

		virtual void Shutdown() = 0;
};
