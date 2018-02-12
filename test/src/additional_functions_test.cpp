#include "gtest/gtest.h"
#include <map>
#include <string>
#include <vector>
#include "additional_functions.hpp"

using namespace testing;

namespace
{

std::map<std::string, size_t> unsorted_map
{
    { "one", 3 },
    { "two", 1 },
    { "three", 5 },
    { "four", 2 }
};

std::vector<std::string> vector_of_strings
{
    "one",
    "two",
    "three",
    "four"
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

TEST(additional_function_test, should_print_what_vector_contains)
{

    internal::CaptureStdout();
    std::cout << vector_of_strings << std::endl;
    std::string output = internal::GetCapturedStdout();

    EXPECT_EQ(output, "[one, two, three, four, \b\b]\n");
}

TEST(additional_function_test, should_print_what_pair_contains)
{
    std::pair<int, std::string> pair_to_check{1, "one"};
    testing::internal::CaptureStdout();
    std::cout << pair_to_check << std::endl;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "<1, one>\n");
}

TEST(additional_function_test, should_print_what_map_contains)
{
    testing::internal::CaptureStdout();
    std::cout << unsorted_map << std::endl;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "[<four, 2>\n"
                      "<one, 3>\n"
                      "<three, 5>\n"
                      "<two, 1>\n"
                      "\b\b]\n");
}

}
}
