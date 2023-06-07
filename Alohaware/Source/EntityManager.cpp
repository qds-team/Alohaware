/*!
 * @author		Rishabh Anand
 * @brief		EntityManager Implementation
!*/


#pragma once

#include <iostream>
#include <assert.h>
#include "EntityManager.hpp"


EntityManager::EntityManager()
{
	// intialize all entity IDs
	for (Entity e = 0; e < MaxEntities; ++e)
	{
		availableEntities.push(e);
	}
}


Entity EntityManager::CreateEntity()
{
	assert(aliveEntities < MaxEntities && "Too many entities in existence.");

	// Take an ID from the front of the queue
	Entity id = availableEntities.front();
	availableEntities.pop();
	++aliveEntities;

	return id;
}


void EntityManager::DestroyEntity(Entity& entity)
{
	assert(aliveEntities < MaxEntities && "Entity out of range");

}


void EntityManager::SetSignature(Entity& entity, Signature& signature)
{
	assert(aliveEntities < MaxEntities && "Entity out of range");

	// Put this entity's signature into the array
	signatures[entity] = signature;
}


Signature EntityManager::GetSignature(const Entity& entity)
{
	assert(aliveEntities < MaxEntities && "Entity out of range");

	// Get this entity's signature from the array
	return signatures[entity];
}
