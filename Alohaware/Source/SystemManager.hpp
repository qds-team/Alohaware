/*!
 * @author		Rishabh Anand
 * @brief		EntityManager Implementation
!*/


#pragma once

#include <iostream>
#include <unordered_map>
#include "System.hpp"


class SystemManager
{
	public:
		template<typename T>
		std::shared_ptr<T> RegisterSystem();

		template<typename T>
		void SetSignature(Signature signature);

		void EntityDestroyed(Entity entity);

		void EntitySignatureChanged(Entity entity, Signature entitySignature);


	private:
		// Map from system type string pointer to a signature
		std::unordered_map<const char*, Signature> signatures{};

		// Map from system type string pointer to a system pointer
		std::unordered_map<const char*, std::shared_ptr<System>> systems{};
};