#pragma once

#include "types.h"
#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	struct GLEWCoreInfo {
		// Coming soon ...
	}; // struct GLEWInfo

	class GLEWCore {
	public:

		using VertexType = vertex3;

	protected:

		struct CoreImpl_ {
			static bool isInitialized;
			void build(const GLEWCoreInfo& info = GLEWCoreInfo{});
		};

	protected:

		utilities::PimplPtr<CoreImpl_> coreImpl_;

	};

} // namespace goofe::graphic
