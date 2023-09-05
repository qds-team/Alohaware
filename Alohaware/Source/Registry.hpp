/*!
 * @author		Rishabh Anand
 * @brief		Component and System Registry
!*/

#include <iostream>
#include <vector>
#include "System.hpp"

#include "Logger.hpp"
#include "Rigidbody.hpp"
#include "Transform.hpp"

#include "GraphicsSystem.hpp"

#pragma once

// Component Registry
void RegisterComponents(Coordinator& coordinator)
{
	coordinator.RegisterComponent<Logger>();
	coordinator.RegisterComponent<Rigidbody>();
	coordinator.RegisterComponent<Transform>();
}

// System Registry
void RegisterSystems(Coordinator& coordinator)
{
	auto systemPointer = coordinator.RegisterSystem<GraphicsSystem>();
}

// Registers all necessary Components and Systems
void Register(Coordinator& coordinator)
{
	RegisterComponents(coordinator);
	RegisterSystems(coordinator);
}
