#pragma once

#include <cstdint>
#include <string>

#include <gl/glew.h>

#include "glew_core.h"

namespace goofe::graphic {

	class GLEWShaders : virtual public GLEWCore {
	public:

		enum class ShaderPipelineStage {
			VERTEX = GL_VERTEX_SHADER_BIT,
			FRAGMENT = GL_FRAGMENT_SHADER_BIT,
			GEOMETRY = GL_GEOMETRY_SHADER_BIT,
			COMPUTE = GL_COMPUTE_SHADER_BIT
		}; // enum class ShaderPipelineStage

		enum class ShaderType {
			VERTEX = GL_VERTEX_SHADER,
			FRAGMENT = GL_FRAGMENT_SHADER,
			GEOMETRY = GL_GEOMETRY_SHADER,
			COMPUTE = GL_COMPUTE_SHADER
		}; // enum class ShaderType

		struct Shader {
			ShaderType type;
			ShaderPipelineStage stage;
			std::string source;
		}; // struct Shader

		using ShaderPipeline = std::vector<Shader>;

	public:

		void build();

	public:

		std::uint32_t buildShaderProgram(std::uint32_t pipelineID, ShaderType type,
			ShaderPipelineStage stage, const std::string& source);

		std::uint32_t buildShaderPipeline();

		void delShaderPipelineData(std::uint32_t pipelineID, std::vector<std::uint32_t>& programsIDs);

	}; // class GLEWShaders

} // namespace goofe::graphic
