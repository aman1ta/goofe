#pragma once

#include <cstdint>

#include <vector>

#include "glew_in.h"

namespace goofe::graphic {

	struct GLPipeline {
		std::uint32_t id;

		explicit GLPipeline(const GLEWIn::ShaderPipeline& pipeline);
		~GLPipeline();

	private:

		struct Impl_ {
			std::vector<std::uint32_t> programsIDs;
			GLEWIn inputManager;
		};

	private:

		utilities::PimplPtr<Impl_> impl_;
	};

} // namespace goofe::graphic
