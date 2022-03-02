#pragma once

#include <cstddef>
#include <cstdint>

#include <string>
#include <string_view>

#include "../config.h"
#include "../utilities/pimpl_pointer.hpp"

namespace goofe::graphic {

	constexpr bool WINDOW_DEFAULT_RESIZABLE{ false };

	constexpr std::size_t WINDOW_DEFAULT_WIDTH{ 640 };
	constexpr std::size_t WINDOW_DEFAULT_HEIGHT{ 480 };

	constexpr std::string_view WINDOW_DEFAULT_TITLE{ ENGINE_NAME };

}

namespace goofe::graphic {

	struct WindowInfo {
		bool isResizable;
		std::size_t width, height;
		std::string title;
	}; // struct WindowInfo

	template <typename SubSys>
	class Window {
	public:

		explicit constexpr Window(const WindowInfo& info =
			WindowInfo{ .isResizable = WINDOW_DEFAULT_RESIZABLE,
						.width = WINDOW_DEFAULT_WIDTH,
						.height = WINDOW_DEFAULT_HEIGHT,
						.title = WINDOW_DEFAULT_TITLE.data()});
		~Window();

	public:

		void show() noexcept;
		bool isOpen() noexcept;

	private:

		struct Impl_ {
			SubSys subSys;
			SubSys::window_ptr wndPtr;
		}; // struct Impl_

	private:

		utilities::PimplPtr<Impl_> impl_;

	}; // class Window<SubSys>

	template<typename SubSys>
	constexpr Window<SubSys>::Window(const WindowInfo& info)
	{
		try {
			impl_->subSys.build();
			impl_->wndPtr = impl_->subSys.buildWindow(info.title, info.width, info.height,
				info.isResizable);
		}
		catch (...) {
			throw;
		}
	}

	template<typename SubSys>
	Window<SubSys>::~Window()
	{
		impl_->subSys.destroy();
	}

	template<typename SubSys>
	void Window<SubSys>::show() noexcept
	{
		impl_->subSys.showWindow(impl_->wndPtr);
	}

	template<typename SubSys>
	bool Window<SubSys>::isOpen() noexcept
	{
		return !impl_->subSys.isWindowShouldClose(impl_->wndPtr);
	}

} // namespace goofe::graphic
