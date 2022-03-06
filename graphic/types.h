#pragma once

#include <cstddef>
#include <cstdint>

#include <vector>

#include <glm/ext/vector_float3.hpp>

namespace goofe::graphic {

	using point3f = glm::vec3;

	using color3f = glm::vec3;
	using rgb = color3f;
	using cymk = color3f;

	struct vertex3 {
		point3f position;
		// Color
		// UV
		// ...
	}; // struct vertex3

	struct PackedScene {
		std::vector<std::uint32_t> indices;
		std::vector<vertex3> vertices;
		std::vector<PackedScene> children;
	};

} // namespace goofe::graphic
