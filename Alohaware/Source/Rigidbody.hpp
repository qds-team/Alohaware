#include <iostream>
#include "glm/vec3.hpp"

#pragma once

class Rigidbody
{
	float mass;
	glm::vec3 velocity;
	glm::vec3 acceleration;
};