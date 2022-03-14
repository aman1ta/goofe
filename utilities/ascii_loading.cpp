#include <streambuf>
#include <fstream>
#include <memory>
#include "ascii_loading.h"

std::string
goofe::utilities::loadASCII(const std::filesystem::path& path)
{
    return std::string(
        (std::istreambuf_iterator<char>(
            *(std::make_unique<std::ifstream>(
                path
                )).get()
            )),
        std::istreambuf_iterator<char>()
    );
}
