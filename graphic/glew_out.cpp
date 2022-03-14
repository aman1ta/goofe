#include <any>
#include <algorithm>

#include "glew_out.h"

void 
goofe::graphic::GLEWOut::build()
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
	std::for_each(pipeline.uniforms.begin(), pipeline.uniforms.end(),
		[&](const auto& uniform) {
			auto location = impl_->uniformManager.getLocation(uniform.shaderProgramID, uniform.name);
			impl_->uniformManager.load(uniform.shaderProgramID, location, uniform);
		}
	);
}

void
goofe::graphic::GLEWOut::renderScene(const SceneType& scene, RenderingLevel level)
{
	glBindVertexArray(scene.id);
	glDrawElements(static_cast<GLenum>(level), scene.indices_count, GL_UNSIGNED_INT, 
		reinterpret_cast<void*>(scene.indices_offset));
}
