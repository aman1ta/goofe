#include <stdexcept>

#include <gl/glew.h>

#include "glew_core.h"

bool goofe::graphic::GLEWCore::CoreImpl_::isInitialized = false;

void 
goofe::graphic::GLEWCore::CoreImpl_::build(const GLEWCoreInfo& info)
{
	if (glewInit() != GLEW_OK) {
		auto msg = "[ERROR] goofe::graphic::GLEW::build():\n"
			"| Failed to initialize GLEW library !";
		throw std::runtime_error(msg);
	}
	glewExperimental = GL_TRUE;

	isInitialized = true;
}
