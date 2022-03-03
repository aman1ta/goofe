#include <stdexcept>

#include <gl/glew.h>

#include "glew.h"

void 
goofe::graphic::GLEW::build(const GLEWInfo& info)
{
	if (glewInit() != GLEW_OK) {
		auto msg = "[ERROR] goofe::graphic::GLEW::build():\n|Failed to initialize GLEW library !";
		throw std::runtime_error(msg);
	}
	glewExperimental = GL_TRUE;
}

void 
goofe::graphic::GLEW::destroy()
{}

void 
goofe::graphic::GLEW::setClearColor(rgb color) noexcept
{
	glClearColor(color.r, color.g, color.b, 1.0f);
}

void 
goofe::graphic::GLEW::clearViewport() noexcept
{
	glClear(GL_COLOR_BUFFER_BIT);
}
