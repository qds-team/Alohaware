/*!
 * @author		Rishabh Anand
 * @brief		EntityManager Definition
!*/

#pragma once

#include <iostream>
#include <queue>
#include <array>
#include "Entity.hpp"
#include <cassert>

class EntityManager
{
	public:
		EntityManager()
		{
			// intialize all entity IDs
			for (Entity e = 0; e < MaxEntities; ++e)
			{
				availableEntities.push(e);
			}
		}

		Entity CreateEntity()
		{
			assert(aliveEntities < MaxEntities && "Too many entities in existence.");

			// Take an ID from the front of the queue
			Entity id = availableEntities.front();
			availableEntities.pop();
			++aliveEntities;

			return id;
		}

		void DestroyEntity(Entity& entity)
		{
			assert(aliveEntities < MaxEntities && "Entity out of range");

			signatures[entity].reset();

			availableEntities.push(entity);
			--aliveEntities;
		}

		void SetSignature(Entity& entity, Signature& signature)
		{
			assert(aliveEntities < MaxEntities && "Entity out of range");

			// Put this entity's signature into the array
			signatures[entity] = signature;
		}

		Signature GetSignature(const Entity& entity)
		{
			assert(aliveEntities < MaxEntities && "Entity out of range");

			// Get this entity's signature from the array
			return signatures[entity];
		}

	private:
		std::queue<Entity> availableEntities{};

		std::array<Signature, MaxEntities> signatures{};

		std::uint32_t aliveEntities{};
};
