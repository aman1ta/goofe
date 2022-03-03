#include <iostream>
#include "graphic/glew_renderer.hpp"
#include "graphic/glfw_window.hpp"

int main() {
	try {
		goofe::graphic::glfw_window wnd;
		goofe::graphic::glew_renderer r;
		while (wnd.isOpen()) {
			wnd.show();
			r.render();
		}
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}