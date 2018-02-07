#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "consts.hpp"

namespace freq_analizer
{
namespace file_operation
{

using file_content = std::vector<std::string>;

class IFile_reader
{
public:
    ~IFile_reader() = default;

    virtual file_content read_from_file() = 0;
};

class File_reader : public IFile_reader
{
public:
    File_reader(std::string const& path);

    file_content read_from_file() override;

private:
    std::string const& file_path_;
    file_content content_;
};

}
}

