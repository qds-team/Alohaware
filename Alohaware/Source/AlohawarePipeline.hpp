#pragma once

#include <string>
#include <vector>

namespace Alohaware
{
	class AlohawarePipeline {
	public:
		AlohawarePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
	};
}