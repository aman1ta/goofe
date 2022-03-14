#pragma once

#include <filesystem>
#include <string>

#include "../utilities/ascii_loading.h"

namespace goofe::graphic {

	struct ShaderLoader {
		ShaderLoader() = default;
		ShaderLoader(const ShaderLoader& other) = delete;
		ShaderLoader(ShaderLoader&& other) = delete;

		std::string operator ()(const std::filesystem::path& path);
	};

} // namespace goofe::graphic
