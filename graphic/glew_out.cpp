#include "glew_out.h"

void 
goofe::graphic::GLEWOut::build(const GLEWOutInfo& info)
{
	if (!coreImpl_->isInitialized) {
		try {
			coreImpl_->build();
		} catch (...) {
			throw;
		}
	}
}

void 
goofe::graphic::GLEWOut::destroy()
{}

void
goofe::graphic::GLEWOut::setClearColor(rgb color) noexcept
{
	glClearColor(color.r, color.g, color.b, 1.0f);
}

void 
goofe::graphic::GLEWOut::clearViewport() noexcept
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void 
goofe::graphic::GLEWOut::useShaderPipeline(const ShaderPipelineType& pipeline)
{
	glBindProgramPipeline(pipeline.id);
}

void
goofe::graphic::GLEWOut::renderScene(const SceneType& scene, RenderingLevel level)
{
	glBindVertexArray(scene.id);
	glDrawElements(static_cast<GLenum>(level), scene.indices_count, GL_UNSIGNED_INT, 
		reinterpret_cast<void*>(scene.indices_offset));
}
