#include <iostream>
#include "glm/vec3.hpp"

#pragma once

class Rigidbody
{
	public:
		float gravity;
		bool hasGravity;

		float mass;
		glm::vec3 velocity;
		glm::vec3 acceleration;


};