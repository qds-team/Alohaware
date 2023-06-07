/*!
 * @author		Rishabh Anand
 * @brief		ComponentManager Implementation
!*/


#pragma once

#include "ComponentManager.hpp"
#include <assert.h>


template<typename T>
void ComponentArray<T>::InsertData(Entity entity, T component)
{
	assert(entityToIndexMap.find(entity) == entityToIndexMap.end() && "Component added to same entity more than once.");

	// Put new entry at end and update the maps
	size_t newIndex = size;
	entityToIndexMap[entity] = newIndex;
	indexToEntityMap[newIndex] = entity;
	componentArray[newIndex] = component;
	++size;
}


template<typename T>
void ComponentArray<T>::RemoveData(Entity entity)
{
	assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Removing non-existent component.");

	// Copy element at end into deleted element's place to maintain density
	size_t indexOfRemovedEntity = entityToIndexMap[entity];
	size_t indexOfLastElement = size - 1;
	componentArray[indexOfRemovedEntity] = componentArray[indexOfLastElement];

	// Update map to point to moved spot
	Entity entityOfLastElement = indexToEntityMap[indexOfLastElement];
	entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
	indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

	entityToIndexMap.erase(entity);
	indexToEntityMap.erase(indexOfLastElement);

	--size;
}


template<typename T>
T& ComponentArray<T>::GetData(Entity entity) const
{
	assert(entityToIndexMap.find(entity) != entityToIndexMap.end() && "Retrieving non-existent component.");

	// Return a reference to the entity's component
	return componentArray[entityToIndexMap[entity]];
}


template<typename T>
void ComponentArray<T>::EntityDestroyed(Entity entity)
{
	if (entityToIndexMap.find(entity) != entityToIndexMap.end())
	{
		// Remove the entity's component if it existed
		RemoveData(entity);
	}
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


template<typename T>
void ComponentManager::RegisterComponent()
{
	const char* typeName = typeid(T).name();

	assert(componentTypes.find(typeName) == componentTypes.end() && "Registering component type more than once.");

	// Add this component type to the component type map
	componentTypes.insert({ typeName, nextComponentType });

	// Create a ComponentArray pointer and add it to the component arrays map
	componentArrays.insert({ typeName, std::make_shared<ComponentArray<T>>() });

	// Increment the value so that the next component registered will be different
	++nextComponentType;
}


template<typename T>
ComponentType ComponentManager::GetComponentType() const
{
	const char* typeName = typeid(T).name();

	assert(componentTypes.find(typeName) != componentTypes.end() && "Component not registered before use.");

	// Return this component's type - used for creating signatures
	return componentTypes[typeName];
}


template<typename T>
void ComponentManager::AddComponent(Entity entity, T component)
{
	// Add a component to the array for an entity
	GetComponentArray<T>()->InsertData(entity, component);
}


template<typename T>
void ComponentManager::RemoveComponent(Entity entity)
{
	// Remove a component from the array for an entity
	GetComponentArray<T>()->RemoveData(entity);
}


template<typename T>
T& ComponentManager::GetComponent(Entity entity) const
{
	// Get a reference to a component from the array for an entity
	return GetComponentArray<T>()->GetData(entity);
}


void ComponentManager::EntityDestroyed(Entity entity)
{
	// Notify each component array that an entity has been destroyed
		// If it has a component for that entity, it will remove it
	for (auto const& pair : componentArrays)
	{
		auto const& component = pair.second;

		component->EntityDestroyed(entity);
	}
}


template<typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::GetComponentArray() const
{
	const char* typeName = typeid(T).name();

	assert(componentTypes.find(typeName) != componentTypes.end() && "Component not registered before use.");

	return std::static_pointer_cast<ComponentArray<T>>(componentArrays[typeName]);
}
