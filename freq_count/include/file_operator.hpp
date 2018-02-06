#pragma once

#include <iostream>

namespace freq_analizer
{

class File_operator
{
public:
    File_operator(std::fstream& file) : file_(file)
    {}

    void read_from_file();

private:
    const std::fstream& file_;
};

}

