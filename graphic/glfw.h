#pragma once

#include <cstddef>
#include <string_view>

#include <memory>

#include <glfw/glfw3.h>

namespace goofe::graphic {

	constexpr std::size_t GLFW_LAST_VERSION_MAJOR{ 4 };
	constexpr std::size_t GLFW_LAST_VERSION_MINOR{ 6 };

} // namespace goofe::graphic

namespace goofe::graphic {

	class GLFW {
	public:

		using window_ptr = std::shared_ptr<GLFWwindow>;

	public:

		void build();
		void destroy();

	public:

		window_ptr buildWindow(std::string_view title, std::size_t width, std::size_t height, 
			bool isResizable);

		void showWindow(window_ptr window) noexcept;
		bool isWindowShouldClose(window_ptr window) noexcept;

	};

} // namespace goofe::graphic
