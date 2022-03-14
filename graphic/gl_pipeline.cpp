#include <iterator>
#include <algorithm>

#include "gl_pipeline.h"

goofe::graphic::GLPipeline::GLPipeline(const GLEWShaders::ShaderPipeline& pipeline)
{
	impl_->shaderManager.build();

	id = impl_->shaderManager.buildShaderPipeline();

	impl_->programsIDs.reserve(pipeline.size());
	std::for_each(pipeline.begin(), pipeline.end(), 
		[&](const auto& prog) {
			auto newShaderProgramID = impl_->shaderManager.buildShaderProgram(id, prog.type, 
				prog.stage, prog.source);
			std::copy(prog.uniforms.begin(), prog.uniforms.end(), std::back_inserter(uniforms)); 
			std::for_each(uniforms.begin(), uniforms.end(),
				[&](auto& uniform) {
					uniform.shaderProgramID = newShaderProgramID;
				}
			);
			impl_->programsIDs.push_back(newShaderProgramID);
		}
	);
}

goofe::graphic::GLPipeline::~GLPipeline()
{
	impl_->shaderManager.delShaderPipelineData(id, impl_->programsIDs);
}
