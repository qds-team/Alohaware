#include <iostream>
#include "glm/vec3.hpp"

#pragma once

class Transform
{
	public:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
};