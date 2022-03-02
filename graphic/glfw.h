#pragma once

#include <cstddef>
#include <string_view>

#include <memory>

#include <glfw/glfw3.h>

namespace goofe::graphic {

	constexpr std::size_t GLFW_LAST_VERSION_MAJOR{ 4 };
	constexpr std::size_t GLFW_LAST_VERSION_MINOR{ 6 };

}

namespace goofe::graphic {

	struct GLFWInfo {
		std::size_t vMajor, vMinor;
	};

	class GLFW {
	public:

		using window_ptr = std::shared_ptr<GLFWwindow>;

	public:

		void build(const GLFWInfo& info = GLFWInfo{ .vMajor = GLFW_LAST_VERSION_MAJOR,
													.vMinor = GLFW_LAST_VERSION_MINOR });
		void destroy();

	public:

		window_ptr buildWindow(std::string_view title, std::size_t width, std::size_t height, 
			bool isResizable);

		void showWindow(window_ptr window) noexcept;
		bool isWindowShouldClose(window_ptr window) noexcept;

	};

}
