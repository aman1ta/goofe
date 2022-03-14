#pragma once

#include <cstdint>
#include <string>
#include <any>

namespace goofe::graphic {

	class GLEWUniforms {
	public:

		enum class UniformType {
			FLOAT
		};

		struct Uniform {
			std::uint32_t shaderProgramID;
			UniformType type;
			std::string name;
			std::any data;
		};

	public:

		std::uint32_t getLocation(std::uint32_t shaderProgramID, const std::string& name);
		void load(std::uint32_t shaderProgramID, std::uint32_t location, const Uniform& uniform);

	};

} // namespace goofe::graphic
