#include "GraphicsSystem.hpp"

void GraphicsSystem::Initialize()
{
	if (!glfwInit())
	{
		// Handle error, e.g., print an error message
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate(); // Terminate GLFW
	}
}

void GraphicsSystem::Update(float dt)
{
	if (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}

void GraphicsSystem::Shutdown()
{

}