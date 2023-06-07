/*!
 * @author		Rishabh Anand
 * @brief		ComponentManager Definition
!*/


#pragma once

#include <iostream>
#include <unordered_map>
#include "Component.hpp"
#include "Entity.hpp"


class IComponentArray
{
	public:
		virtual ~IComponentArray() = default;
		virtual void EntityDestroyed(Entity entity) = 0;
};


template<typename T>
class ComponentArray : public IComponentArray
{
	public:
		void InsertData(Entity entity, T component);

		void RemoveData(Entity entity);

		T& GetData(Entity entity) const;

		void EntityDestroyed(Entity entity) override;

	private:
		// The packed array of components (of generic type T),
		// set to a specified maximum amount, matching the maximum number
		// of entities allowed to exist simultaneously, so that each entity
		// has a unique spot.
		std::array<T, MaxEntities> componentArray;

		// Map from an entity ID to an array index.
		std::unordered_map<Entity, size_t> entityToIndexMap;

		// Map from an array index to an entity ID.
		std::unordered_map<size_t, Entity> indexToEntityMap;

		// Total size of valid entries in the array.
		size_t size;
};


class ComponentManager
{
	public:
		template<typename T>
		void RegisterComponent();

		template<typename T>
		ComponentType GetComponentType() const;

		template<typename T>
		void AddComponent(Entity entity, T component);

		template<typename T>
		void RemoveComponent(Entity entity);

		template<typename T>
		T& GetComponent(Entity entity) const;

		void EntityDestroyed(Entity entity);


	private:
		// Map from type string pointer to a component type
		std::unordered_map<const char*, ComponentType> componentTypes{};

		// Map from type string pointer to a component array
		std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays{};

		// The component type to be assigned to the next registered component - starting at 0
		ComponentType nextComponentType{};

		template<typename T>
		std::shared_ptr<ComponentArray<T>> GetComponentArray() const;
};
