#pragma once

#include <cstdint>

#include "types.h"
#include "glew_vertices.h"

#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	struct GLScene {
		std::uint32_t id;
		std::size_t indices_offset, indices_count;

		explicit GLScene(const PackedScene& scene);
		~GLScene();

	private:

		struct Impl_ {
			std::uint32_t buf_id;
			GLEWVertices inputManager;
		};

	private:

		utilities::PimplPtr<Impl_> impl_;

	};

} // namespace goofe::graphic
