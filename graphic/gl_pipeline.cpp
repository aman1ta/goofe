#include <algorithm>

#include "gl_pipeline.h"

goofe::graphic::GLPipeline::GLPipeline(const GLEWIn::ShaderPipeline& pipeline)
{
	impl_->inputManager.build();

	id = impl_->inputManager.buildShaderPipeline();

	impl_->programsIDs.reserve(pipeline.size());
	std::for_each(pipeline.begin(), pipeline.end(), 
		[&](const auto& prog) {
			impl_->programsIDs.push_back(impl_->inputManager.buildShaderProgram(id, prog.type, 
				prog.stage, prog.source));
		}
	);
}

goofe::graphic::GLPipeline::~GLPipeline()
{
	impl_->inputManager.delShaderPipelineData(id, impl_->programsIDs);
}
