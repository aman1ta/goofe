#include <algorithm>

#include "glew_in.h"

void 
goofe::graphic::GLEWIn::build(const GLEWInInfo& info)
{
	if (!coreImpl_->isInitialized) {
		try {
			coreImpl_->build();
		}
		catch (...) {
			throw;
		}
	}
	if (!impl_->isInitialized) {
		glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &impl_->alignment);
		impl_->isInitialized = true;
	}
}

goofe::graphic::GLEWIn::VertexData 
goofe::graphic::GLEWIn::calcVertexData(std::size_t indicesSize, std::size_t verticesSize)
{
	uint32_t
		indices_lenb = GLsizei(sizeof(std::size_t) * indicesSize),
		vertices_lenb = GLsizei(sizeof(VertexType) * verticesSize);

	uint32_t
		indices_len_aligned = impl_->align(indices_lenb),
		vertices_len_aligned = impl_->align(vertices_lenb);

	uint32_t indices_offset = vertices_len_aligned;

	return VertexData{ .indices_lenb = indices_lenb,
					   .vertices_lenb = vertices_lenb,
					   .indices_len_aligned = indices_len_aligned,
					   .vertices_len_aligned = vertices_len_aligned,
					   .indices_offset = indices_offset };
}

std::uint32_t
goofe::graphic::GLEWIn::buildVertexBuffer(const std::vector<std::uint32_t>& indices, 
	const std::vector<vertex3>& vertices, const VertexData& vertexData)
{
	std::uint32_t newVertexBufferID{ 0 };
	glCreateBuffers(1, &newVertexBufferID);

	glNamedBufferStorage(
		newVertexBufferID,
		vertexData.indices_len_aligned + vertexData.vertices_len_aligned,
		nullptr,
		GL_DYNAMIC_STORAGE_BIT);

	glNamedBufferSubData(
		newVertexBufferID,
		GL_NONE, vertexData.vertices_lenb,
		vertices.data());
	glNamedBufferSubData(
		newVertexBufferID,
		vertexData.indices_offset, vertexData.indices_lenb,
		indices.data());

	return newVertexBufferID;
}

std::uint32_t 
goofe::graphic::GLEWIn::buildShaderProgram(std::uint32_t pipelineID, ShaderType type, 
	ShaderPipelineStage stage, const std::string& source)
{
	auto c_source = source.c_str();
	std::uint32_t newShaderProgramID = glCreateShaderProgramv(static_cast<GLenum>(type), 1, 
		&c_source);
	glUseProgramStages(pipelineID, static_cast<GLbitfield>(stage), newShaderProgramID);
	return newShaderProgramID;
}

std::uint32_t 
goofe::graphic::GLEWIn::buildVertexArray(std::uint32_t vertexBufID)
{
	std::uint32_t newVertexArrayID{ 0 };
	glCreateVertexArrays(1, &newVertexArrayID);

	glVertexArrayVertexBuffer(
		newVertexArrayID, 0,
		vertexBufID,
		GL_NONE, sizeof(VertexType));
	glVertexArrayElementBuffer(newVertexArrayID, vertexBufID);

	glEnableVertexArrayAttrib(newVertexArrayID, 0);
	glVertexArrayAttribFormat(
		newVertexArrayID,
		0, 3,
		GL_FLOAT, GL_FALSE,
		offsetof(VertexType, position));
	glVertexArrayAttribBinding(newVertexArrayID, 0, 0);

	return newVertexArrayID;
}

std::uint32_t 
goofe::graphic::GLEWIn::buildShaderPipeline()
{
	std::uint32_t newShaderPipelineID{ 0 };
	glCreateProgramPipelines(1, &newShaderPipelineID);
	return newShaderPipelineID;
}

void 
goofe::graphic::GLEWIn::delVertexData(std::uint32_t vertexArrID, std::uint32_t vertexBufID)
{
	glDeleteBuffers(1, &vertexBufID);
	glDeleteVertexArrays(1, &vertexArrID);
}

void 
goofe::graphic::GLEWIn::delShaderPipelineData(std::uint32_t pipelineID, 
	std::vector<std::uint32_t>& programsIDs)
{
	std::for_each(programsIDs.begin(), programsIDs.end(),
		[](const auto& id) {
			glDeleteProgram(id);
		}
	);
	glDeleteProgramPipelines(1, &pipelineID);
}

std::uint32_t
goofe::graphic::GLEWIn::Impl_::align(std::uint32_t lenght)
{
	return (lenght + alignment - 1) & ~(alignment - 1);
}
