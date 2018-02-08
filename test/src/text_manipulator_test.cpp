#include "gtest/gtest.h"
#include "text_manipulator.hpp"
#include <vector>
#include <string>

using namespace ::testing;

namespace
{

std::vector<std::string> text
{
    "first", "first", "first", "first",
    "second", "second", "second",
    "third",
    "fourth", "fourth", "fourth", "fourth", "fourth",
    "fifth", "fifth",
    "sixth", "sixth", "sixth", "sixth", "sixth"
};

}

namespace freq_analizer
{
namespace text_operation
{

struct Text_manipulator_test : Test
{
    Text_manipulator_test() {}

    Text_manipulator sut;
};

TEST_F(Text_manipulator_test, should_count_words)
{
    Word_count_col words
    {
        { "first", 4 },
        { "second", 3 },
        { "third", 1 },
        { "fourth", 5 },
        { "fifth", 2 },
        { "sixth", 5 }
    };

    EXPECT_EQ(sut.count_words(text), words);
}

TEST_F(Text_manipulator_test, should_count_letters)
{
    Letters_count_col letters_count
    {
        {'t', 17},
        {'f', 13},
        {'h', 13},
        {'i', 12},
        {'s', 12},
        {'r', 10},
        {'o', 8},
        {'u', 5},
        {'x', 5},
        {'d', 4},
        {'c', 3},
        {'e', 3},
        {'n', 3}
    };

    EXPECT_EQ(sut.count_letters(text), letters_count);
}

}
}
