#include "file_operator.hpp"

#include <fstream>

namespace
{
constexpr size_t FILE_CONTENT_VEC_START_SIZE = 200;
}

namespace freq_analizer
{
namespace file_operation
{

File_reader::File_reader(std::string const& path) : file_path_(path),
                                                    content_{}
{}

file_content File_reader::get_file_content()
{
    if (content_.size() == 0)
    {
        read_from_file();
    }

    return content_;
}

void File_reader::read_from_file()
{
    content_.reserve(FILE_CONTENT_VEC_START_SIZE);
    std::fstream file(file_path_, std::ios::in);
    std::string line;

    if (file.is_open())
    {
        while (file >> line)
        {
            content_.push_back(line);
        }
    }
}

}
}
