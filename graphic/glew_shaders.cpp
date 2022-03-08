#include <algorithm>

#include "glew_shaders.h"

void
goofe::graphic::GLEWShaders::build()
{
	if (!coreImpl_->isInitialized) {
		try {
			coreImpl_->build();
		}
		catch (...) {
			throw;
		}
	}
}

std::uint32_t
goofe::graphic::GLEWShaders::buildShaderProgram(std::uint32_t pipelineID, ShaderType type,
	ShaderPipelineStage stage, const std::string& source)
{
	auto c_source = source.c_str();
	std::uint32_t newShaderProgramID = glCreateShaderProgramv(static_cast<GLenum>(type), 1,
		&c_source);
	glUseProgramStages(pipelineID, static_cast<GLbitfield>(stage), newShaderProgramID);
	return newShaderProgramID;
}

std::uint32_t
goofe::graphic::GLEWShaders::buildShaderPipeline()
{
	std::uint32_t newShaderPipelineID{ 0 };
	glCreateProgramPipelines(1, &newShaderPipelineID);
	return newShaderPipelineID;
}

void
goofe::graphic::GLEWShaders::delShaderPipelineData(std::uint32_t pipelineID,
	std::vector<std::uint32_t>& programsIDs)
{
	std::for_each(programsIDs.begin(), programsIDs.end(),
		[](const auto& id) {
			glDeleteProgram(id);
		}
	);
	glDeleteProgramPipelines(1, &pipelineID);
}