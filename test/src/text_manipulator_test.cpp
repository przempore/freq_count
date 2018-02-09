#include "gtest/gtest.h"
#include "text_manipulator.hpp"
#include <vector>
#include <string>

using namespace ::testing;

namespace
{

freq_analizer::text_operation::words text
{
    "first", "first", "first", "first",
    "second", "second", "second",
    "third",
    "fourth", "fourth", "fourth", "fourth", "fourth",
    "fifth", "fifth",
    "sixth", "sixth", "sixth", "sixth", "sixth",
    "ssssss"
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
    word_count_col expected_words
    {
        { "first", 4 }, { "second", 3 },
        { "third", 1 }, { "fourth", 5 },
        { "fifth", 2 }, { "sixth", 5 }, { "ssssss", 1 }
    };

    EXPECT_EQ(sut.count_words(text), expected_words);
}

TEST_F(Text_manipulator_test, should_count_letters)
{
    letters_count_col letters_count
    {
        {'t', 17}, {'f', 13}, {'h', 13}, {'i', 12},
        {'s', 18}, {'r', 10}, {'o', 8}, {'u', 5},
        {'x', 5}, {'d', 4}, {'c', 3}, {'e', 3},
        {'n', 3}
    };

    EXPECT_EQ(sut.count_letters(text), letters_count);
    sut.count_N_grams(text, 4);
}

//TEST_F(Text_manipulator_test, should_sort_map)
//{
//    word_count_col words
//    {
//        { "first", 4 }, { "second", 3 },
//        { "third", 1 }, { "fourth", 5 },
//        { "fifth", 2 }, { "sixth", 5 }, { "ssssss", 1 }
//    };

//    auto&& unsorted_map = sut.count_words(text);
//    auto&& sorted_map = sut.sort_map(unsorted_map);

//    EXPECT_EQ(sorted_map.size(), unsorted_map.size());

//}

}
}
