#pragma once

#include <iostream>
#include "System.hpp"
#include "glm/vec3.hpp"
#include "Rigidbody.hpp"
#include "Transform.hpp"

class PhysicsSystem : public System
{
	public:
		void Initialize();

		void Update(float dt);

		void Shutdown();

	private:
		void ApplyForce(Rigidbody& rigidbody, glm::vec3& force);

		void UpdateRigidbody(Rigidbody& rigidbody, Transform& transform, float dt);

};