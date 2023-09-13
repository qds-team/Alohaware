#pragma once

#include <iostream>
#include "System.hpp"
#include "Window.hpp"
#include "AlohawarePipeline.hpp"

#pragma once

namespace Alohaware
{
	class GraphicsSystem : public System
	{
	public:

		void Initialize();

		void Update(float dt);

		void Shutdown();

		static constexpr int HEIGHT = 1080;
		static constexpr int WIDTH = 1920;

	private:
		Window window{ WIDTH, HEIGHT, "Hello Vulkan!" };
		AlohawarePipeline alohawarePipeline{ "Shaders/simple_shader.vert.spv", "Shaders/simple_shader.frag.spv" };
	};
}