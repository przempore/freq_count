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
    const auto&& sorted_map = sort_map(unsorted_map);

    EXPECT_EQ(unsorted_map.size(), sorted_map.size());

    const std::map<size_t, std::vector<std::string>, std::greater<size_t>> expected_map
    {
        { 1, {"two"} },
        { 2, {"four"} },
        { 3, {"one"} },
        { 5, {"three"} }
    };

    EXPECT_EQ(sorted_map, expected_map);
}

}
}
