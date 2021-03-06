#include <iostream>
#include <string>

#include "graphic/gl_pipeline.h"
#include "graphic/gl_scene.h"

#include "graphic/gl_renderer.hpp"
#include "graphic/glfw_window.hpp"

int main() {

	std::string vertexSource{
		"#version 400 core\n"
		"layout(location = 0) in vec3 position;\n"
		"out vec4 vertexColor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position, 1.0);\n"
		"vertexColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
		"}\n" };
	std::string fragmentSource{
		"#version 400 core\n"
		"uniform float animation;\n"
		"in vec4 vertexColor;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vertexColor * animation;\n"
		"}\n" };

	goofe::graphic::GLEWShaders::Shader vertexShader{
		.type = goofe::graphic::GLEWShaders::ShaderType::VERTEX,
		.stage = goofe::graphic::GLEWShaders::ShaderPipelineStage::VERTEX,
		.source = vertexSource};
	goofe::graphic::GLEWShaders::Shader fragmentShader{
		.type = goofe::graphic::GLEWShaders::ShaderType::FRAGMENT,
		.stage = goofe::graphic::GLEWShaders::ShaderPipelineStage::FRAGMENT,
		.source = fragmentSource,
		.uniforms = {goofe::graphic::GLEWUniforms::Uniform{
			.type = goofe::graphic::GLEWUniforms::UniformType::FLOAT,
			.name = "animation",
			.data = 0.5f}}};

	goofe::graphic::GLEWShaders::ShaderPipeline pipeline{ vertexShader, fragmentShader };

	goofe::graphic::PackedScene scene;
	scene.indices = { 0, 1, 2,
					  2, 1, 3 };
	scene.vertices = { goofe::graphic::vertex3{.position = {-0.5f, -0.5f, 0.0f}},
					   goofe::graphic::vertex3{.position = {0.5f, -0.5f, 0.0f}},
					   goofe::graphic::vertex3{.position = {-0.5f, 0.5f, 0.0f}},
					   goofe::graphic::vertex3{.position = {0.5f, 0.5f, 0.0f}} };

	try {
		goofe::graphic::glfw_window wnd;
		goofe::graphic::gl_renderer r;

		goofe::graphic::GLPipeline glPipeline(pipeline);
		goofe::graphic::GLScene glScene(scene);

		while (wnd.isOpen()) {
			r.render(glPipeline, glScene, goofe::graphic::gl_renderer::RenderingLevel::SURFACE);
			wnd.show();
		}
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
