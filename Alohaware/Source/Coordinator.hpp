/*!
 * @author		Rishabh Anand
 * @brief		Coordinator Implementation
!*/


#pragma once

#include "Entity.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"


class Coordinator
{
	public:
		void Initialize();

		Entity CreateEntity();

		void DestroyEntity(Entity entity);

		template<typename T>
		void RegisterComponent();

		template<typename T>
		void AddComponent(Entity entity, T component);

		template<typename T>
		void RemoveComponent(Entity entity);

		template<typename T>
		T& GetComponent(Entity entity);

		template<typename T>
		ComponentType GetComponentType();

		template<typename T>
		std::shared_ptr<T> RegisterSystem();

		template<typename T>
		void SetSystemSignature(Signature signature);


	private:
		std::unique_ptr<EntityManager> entityManager{};
		std::unique_ptr<ComponentManager> componentManager{};
		std::unique_ptr<SystemManager> systemManager{};
};
