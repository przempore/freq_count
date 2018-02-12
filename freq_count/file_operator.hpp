#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace freq_analizer
{
namespace file_operation
{

using file_content = std::vector<std::string>;

class IFile_reader
{
public:
    ~IFile_reader() = default;

    virtual file_content const& get_file_content() = 0;
};

class File_reader : public IFile_reader
{
public:
    File_reader(std::string const& path);

    file_content const& get_file_content() override;
private:
    void read_from_file();

private:
    std::string const& file_path_;
    file_content content_;
};

}
}

