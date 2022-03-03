#pragma once

#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	struct RendererInfo {
		// Coming soon ...
	}; // struct RendererInfo

	template <typename SubSys>
	class Renderer {
	public:

		explicit constexpr Renderer(const RendererInfo& info);
		~Renderer();

	private:

		struct Impl_ {
			SubSys subSys;
		}; // struct Impl_

	private:

		utilities::PimplPtr<Impl_> impl_;

	}; // class Renderer<SubSys>

	template<typename SubSys>
	constexpr Renderer<SubSys>::Renderer(const RendererInfo& info)
	{
		try {
			impl_->subSys.build();
		} catch (...) {
			throw;
		}
	}

	template<typename SubSys>
	Renderer<SubSys>::~Renderer()
	{
		impl_->subSys.destroy();
	}

} // namespace goofe::graphic
