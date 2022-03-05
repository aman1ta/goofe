#pragma once

#include <cstdint>

#include "types.h"
#include "glew_in.h"

#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	struct GLScene {
		std::uint32_t id, buf_id;
		std::size_t indices_offset, indices_count;

		explicit GLScene(const PackedScene& scene);
		~GLScene();

	private:

		struct Impl_ {
			GLEWIn memManager;
		};

	private:

		utilities::PimplPtr<Impl_> impl_;

	};

} // namespace goofe::graphic
