#pragma once

#include <cstdint>

#include <vector>

#include "glew_shaders.h"

namespace goofe::graphic {

	struct GLPipeline {
	public:

		using UniformType = GLEWUniforms::Uniform;

	public:

		std::uint32_t id;
		std::vector<UniformType> uniforms;

		explicit GLPipeline(const GLEWShaders::ShaderPipeline& pipeline);
		~GLPipeline();

	private:

		struct Impl_ {
			std::vector<std::uint32_t> programsIDs;
			GLEWShaders shaderManager;
		};

	private:

		utilities::PimplPtr<Impl_> impl_;
	};

} // namespace goofe::graphic
