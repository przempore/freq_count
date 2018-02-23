#include "gtest/gtest.h"
#include <map>
#include <string>
#include <vector>
#include "additional_functions.hpp"

using namespace testing;

namespace
{

const std::string one {"one"};
const std::string two {"two"};
const std::string three {"three"};
const std::string four {"four"};

constexpr size_t one_occurance = 3;
constexpr size_t two_occurance = 1;
constexpr size_t three_occurance = 5;
constexpr size_t four_occurance = 2;


const std::map<std::string, size_t> unsorted_map
{
    { one, one_occurance },
    { two, two_occurance },
    { three, three_occurance },
    { four, four_occurance }
};

const std::vector<std::string> vector_of_strings
{
    one, two,
    three, four
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
        { two_occurance, {two} },
        { four_occurance, {four} },
        { one_occurance, {one} },
        { three_occurance, {three} }
    };

    EXPECT_EQ(sorted_map, expected_map);
}

TEST(additional_function_test, should_print_what_vector_contains)
{

    internal::CaptureStdout();
    std::cout << vector_of_strings << std::endl;
    std::string output = internal::GetCapturedStdout();
    std::string expected {"[" + one + ", " + two + ", " + three + ", " + four + ", \b\b]\n"};

    EXPECT_EQ(output, expected);
}

TEST(additional_function_test, should_print_what_pair_contains)
{
    std::pair<int, std::string> pair_to_check{1, one};
    testing::internal::CaptureStdout();
    std::cout << pair_to_check << std::endl;
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected { "<1, " + one  + ">\n" };
    EXPECT_EQ(output, expected);
}

TEST(additional_function_test, should_print_what_map_contains)
{
    testing::internal::CaptureStdout();
    std::cout << unsorted_map << std::endl;
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected { "[<" + four + ", " + std::to_string(four_occurance) + "> <"
                            + one + ", " + std::to_string(one_occurance) + "> <"
                            + three + ", " + std::to_string(three_occurance) + "> <"
                            + two + ", " + std::to_string(two_occurance) + "> \b\b]\n" };

    EXPECT_EQ(output, expected);
}

}
}
