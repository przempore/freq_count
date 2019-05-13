#include "gtest/gtest.h"
#include "file_operator.hpp"
#include <string>

using namespace ::testing;

namespace freq_analizer
{
namespace file_operation
{

struct file_operator_test : Test
{
    file_operator_test() : file_path("Makefile"),
                        sut(std::make_unique<File_reader>(file_path))
    {}

    std::string file_path;
    std::unique_ptr<IFile_reader> sut;
};

TEST_F(file_operator_test, should_read_file)
{
    file_content content;
    content = sut->get_file_content();

    ASSERT_TRUE(content.size() != 0);
}

}
}

 
