#pragma once

#include <gl/glew.h>

#include "types.h"
#include "glew_core.h"
#include "gl_scene.h"

namespace goofe::graphic {

	struct GLEWOutInfo {
		// Coming soon ...
	}; // struct GLEWMemoryInfo

	class GLEWOut : virtual public GLEWCore {
	public:

		using SceneType = GLScene;

		enum class RenderingLevel : std::uint8_t {
			VERTEX = GL_POINTS,
			EDGE = GL_LINE_STRIP,
			SURFACE = GL_TRIANGLES
		};

	public:

		void build(const GLEWOutInfo& info = GLEWOutInfo{});
		void destroy();

	public:

		void setClearColor(rgb color) noexcept;
		void clearViewport() noexcept;

		void renderScene(const SceneType& scene, RenderingLevel level);

	};

} // namespace goofe::graphic
