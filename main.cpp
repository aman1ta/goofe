#include <iostream>
#include "graphic/renderer.hpp"
#include "graphic/glfw_window.hpp"

int main() {
	try {
		goofe::graphic::glfw_window wnd;
		while (wnd.isOpen()) {
			wnd.show();
		}
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}