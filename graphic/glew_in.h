#pragma once

#include <cstddef>
#include <cstdint>

#include "types.h"
#include "glew_core.h"

#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	struct GLEWInInfo {
		// Coming soon ...
	}; // struct GLEWMemoryInfo

	class GLEWIn : virtual public GLEWCore {
	public:

		struct VertexData {
			std::uint32_t indices_lenb, vertices_lenb;
			std::uint32_t indices_len_aligned, vertices_len_aligned;
			std::uint32_t indices_offset;
		};

	public:

		void build(const GLEWInInfo& info = GLEWInInfo{});

	public:

		VertexData calcVertexData(std::size_t indicesSize, std::size_t verticesSize);

		std::uint32_t buildVertexBuffer(const std::vector<std::uint32_t>& indices,
			const std::vector<vertex3>& vertices, const VertexData& vertexData);

		std::uint32_t buildVertexArray(std::uint32_t vertexBufID);

		void delVertexData(std::uint32_t vertexArrID, std::uint32_t vertexBufID);

	private:

		struct Impl_ {
			std::int32_t alignment;

			std::size_t align(std::size_t lenght);
		};

	private:

		utilities::PimplPtr<Impl_> impl_;

	};

} // namespace goofe::graphic
