#include <stdexcept>
#include <format>

#include "glfw.h"

void 
goofe::graphic::GLFW::build()
{
	if (glfwInit() != GLFW_TRUE) {
		auto msg = std::format(
			"[ERROR] goofe::graphic::GLFW::build():\n|Failed to initialize GLFW {}.{} library !",
			GLFW_LAST_VERSION_MAJOR, GLFW_LAST_VERSION_MINOR);
		throw std::runtime_error(msg);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_LAST_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_LAST_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void 
goofe::graphic::GLFW::destroy()
{
	glfwTerminate();
}

goofe::graphic::GLFW::window_ptr 
goofe::graphic::GLFW::buildWindow(std::string_view title, std::size_t width, std::size_t height, 
	bool isResizable)
{
	auto newWindow = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
	if (!newWindow) {
		auto msg = "[ERROR] goofe::graphic::GLFW::buildWindow():\n|Failed to create window !";
		throw std::runtime_error(msg);
	}

	glfwMakeContextCurrent(newWindow);

	return window_ptr(newWindow, glfwDestroyWindow);
}

void 
goofe::graphic::GLFW::showWindow(window_ptr window) noexcept
{
	glfwPollEvents();
	glfwSwapBuffers(window.get());
}

bool 
goofe::graphic::GLFW::isWindowShouldClose(window_ptr window) noexcept
{
	return glfwWindowShouldClose(window.get());
}
