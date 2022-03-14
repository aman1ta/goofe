#include <gl/glew.h>

#include "glew_uniforms.h"

std::uint32_t 
goofe::graphic::GLEWUniforms::getLocation(std::uint32_t shaderProgramID, const std::string& name)
{
    return glGetUniformLocation(shaderProgramID, name.c_str());
}

void
goofe::graphic::GLEWUniforms::load(std::uint32_t shaderProgramID, std::uint32_t location, 
	const Uniform& uniform)
{
	switch (uniform.type) {
	case UniformType::FLOAT:
		glProgramUniform1f(shaderProgramID, location, std::any_cast<float>(uniform.data));
		break;
	}
}
