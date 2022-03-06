#pragma once

#include <cstddef>
#include <cstdint>

#include <string>

#include <vector>

#include <gl/glew.h>

#include "types.h"
#include "glew_core.h"

#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	struct GLEWInInfo {
		// Coming soon ...
	}; // struct GLEWMemoryInfo

	class GLEWIn : virtual public GLEWCore {
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

		struct VertexData {
			std::uint32_t indices_lenb, vertices_lenb;
			std::uint32_t indices_len_aligned, vertices_len_aligned;
			std::uint32_t indices_offset;
		}; // struct VertexData

		using ShaderPipeline = std::vector<Shader>;

	public:

		void build(const GLEWInInfo& info = GLEWInInfo{});

	public:

		VertexData calcVertexData(std::size_t indicesSize, std::size_t verticesSize);

		std::uint32_t buildVertexBuffer(const std::vector<std::uint32_t>& indices,
			const std::vector<vertex3>& vertices, const VertexData& vertexData);
		std::uint32_t buildShaderProgram(std::uint32_t pipelineID, ShaderType type, 
			ShaderPipelineStage stage, const std::string& source);

		std::uint32_t buildVertexArray(std::uint32_t vertexBufID);
		std::uint32_t buildShaderPipeline();

		void delVertexData(std::uint32_t vertexArrID, std::uint32_t vertexBufID);
		void delShaderPipelineData(std::uint32_t pipelineID, std::vector<std::uint32_t>& programsIDs);

	private:

		struct Impl_ {
			bool isInitialized{ false };
			std::int32_t alignment{ 0 };

			std::uint32_t align(std::uint32_t lenght);
		};

	private:

		utilities::PimplPtr<Impl_> impl_;

	};

} // namespace goofe::graphic
