#include <iostream>

#include "graphic/gl_scene.h"

#include "graphic/gl_renderer.hpp"
#include "graphic/glfw_window.hpp"

int main() {
	try {
		goofe::graphic::PackedScene scene;
		scene.indices = {
			0, 1, 2,
			2, 1, 3
		};
		scene.vertices = {
			goofe::graphic::vertex3{.position = {-0.5f, -0.5f, 0.0f}},
			goofe::graphic::vertex3{.position = {0.5f, -0.5f, 0.0f}},
			goofe::graphic::vertex3{.position = {-0.5f, 0.5f, 0.0f}},
			goofe::graphic::vertex3{.position = {0.5f, 0.5f, 0.0f}}
		};

		goofe::graphic::glfw_window wnd;
		goofe::graphic::gl_renderer r;

		goofe::graphic::GLScene glScene(scene);

		while (wnd.isOpen()) {
			r.render(glScene, goofe::graphic::gl_renderer::RenderingLevel::SURFACE);
			wnd.show();
		}
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}