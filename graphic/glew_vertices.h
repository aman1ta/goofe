#pragma once

#include <cstdint>

#include <vector>

#include "types.h"
#include "glew_core.h"

#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	class GLEWVertices : virtual public GLEWCore {
	public:

		struct VertexData {
			std::uint32_t indices_lenb, vertices_lenb;
			std::uint32_t indices_len_aligned, vertices_len_aligned;
			std::uint32_t indices_offset;
		}; // struct VertexData

	public:

		void build();

	public:

		VertexData calcVertexData(std::size_t indicesSize, std::size_t verticesSize);

		std::uint32_t buildVertexBuffer(const std::vector<std::uint32_t>& indices,
			const std::vector<vertex3>& vertices, const VertexData& vertexData);
		std::uint32_t buildVertexArray(std::uint32_t vertexBufID);

		void delVertexData(std::uint32_t vertexArrID, std::uint32_t vertexBufID);

	private:

		struct Impl_ {
			bool isInitialized{ false };
			std::int32_t alignment{ 0 };

			std::uint32_t align(std::uint32_t lenght);
		};

	private:

		utilities::PimplPtr<Impl_> impl_;

	}; // class GLEWVertices

} // namespace goofe::graphic
