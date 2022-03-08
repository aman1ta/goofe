#pragma once

#include <cstdint>

#include <vector>

#include "glew_shaders.h"

namespace goofe::graphic {

	struct GLPipeline {
		std::uint32_t id;

		explicit GLPipeline(const GLEWShaders::ShaderPipeline& pipeline);
		~GLPipeline();

	private:

		struct Impl_ {
			std::vector<std::uint32_t> programsIDs;
			GLEWShaders inputManager;
		};

	private:

		utilities::PimplPtr<Impl_> impl_;
	};

} // namespace goofe::graphic
