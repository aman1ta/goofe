#include "shader_loader.h"

std::string 
goofe::graphic::ShaderLoader::operator()(const std::filesystem::path& path)
{
    return utilities::loadASCII(path);
}
