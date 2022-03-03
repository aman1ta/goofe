#pragma once

#include "types.h"

namespace goofe::graphic {

	struct GLEWInfo {
		// Coming soon ...
	};

	class GLEW {
	public:

		void build(const GLEWInfo& info = GLEWInfo{});
		void destroy();

	public:

		void setClearColor(rgb color) noexcept;
		void clearViewport() noexcept;

	};

} // namespace goofe::graphic
