#include "gtest/gtest.h"
#include <map>
#include <string>
#include <vector>
#include "additional_functions.hpp"

namespace
{

std::map<std::string, size_t> unsorted_map
{
    { "one", 3 },
    { "two", 1 },
    { "three", 5 },
    { "four", 2 }
};

}

namespace freq_analizer
{
namespace functions
{

TEST(additional_function_test, should_sort_map)
{
    auto&& sorted_map = sort_map(unsorted_map);

    EXPECT_EQ(unsorted_map.size(), sorted_map.size());

    std::map<std::string, size_t> expected_map
    {
        { "two", 1 },
        { "four", 2 },
        { "one", 3 },
        { "three", 5 }
    };


    EXPECT_EQ(sorted_map, expected_map);
}

}
}
