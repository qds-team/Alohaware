/*!
 * @author		Rishabh Anand
 * @brief		EntityManager Definition
!*/


#pragma once

#include <iostream>
#include <queue>
#include <array>
#include "Entity.hpp"


class EntityManager
{
	public:
		EntityManager();

		Entity CreateEntity();
		
		void DestroyEntity(Entity& entity);

		void SetSignature(Entity& entity, Signature& signature);

		Signature GetSignature(const Entity& entity);


	private:
		std::queue<Entity> availableEntities{};

		std::array<Signature, MaxEntities> signatures{};

		std::uint32_t aliveEntities{};
};
