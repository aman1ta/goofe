#pragma once

#include "types.h"
#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	constexpr rgb VIEWPORT_DEFAULT_CLEAR_COLOR{ 0.7f, 0.7f, 0.7f };

} // namespace goofe::graphic

namespace goofe::graphic {

	struct RendererInfo {
		rgb clearColor;
	}; // struct RendererInfo

	template <typename SubSys>
	class Renderer {
	public:

		using RenderingLevel = SubSys::RenderingLevel;

	public:

		explicit constexpr Renderer(const RendererInfo& info = 
			RendererInfo{ .clearColor = VIEWPORT_DEFAULT_CLEAR_COLOR} );
		~Renderer();

	public:

		void render(const typename SubSys::SceneType& scene, RenderingLevel level) noexcept;

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
		impl_->subSys.setClearColor(info.clearColor);
	}

	template<typename SubSys>
	Renderer<SubSys>::~Renderer()
	{
		impl_->subSys.destroy();
	}

	template<typename SubSys>
	void Renderer<SubSys>::render(const typename SubSys::SceneType& scene, RenderingLevel level)
		noexcept
	{
		impl_->subSys.clearViewport();
		impl_->subSys.renderScene(scene, level);
	}

} // namespace goofe::graphic
