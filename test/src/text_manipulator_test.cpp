#include "gtest/gtest.h"
#include "text_manipulator.hpp"
#include <vector>
#include <string>

using namespace ::testing;

namespace
{

freq_analizer::text_operation::words_t text
{
    "first", "first", "first", "first",
    "second", "second", "second",
    "third",
    "fourth", "fourth", "fourth", "fourth", "fourth",
    "fifth", "fifth",
    "sixth", "sixth", "sixth", "sixth", "sixth",
    "ssssss"
};

freq_analizer::text_operation::words_t text_with_multiple_words_separated_with_slashes
{
    "main/CMakeFiles/freq_analizer_app.dir/build",
    "main/CMakeFiles/freq_analizer_app.dir/main.cpp.i",
    "main/CMakeFiles/freq_analizer_app.dir/rule"
};

}

namespace freq_analizer
{
namespace text_operation
{

struct Text_manipulator_test : Test
{
    Text_manipulator object_under_test;
};

TEST_F(Text_manipulator_test, should_count_words)
{
    word_count_col expected_words
    {
        { "first", 4 }, { "second", 3 },
        { "third", 1 }, { "fourth", 5 },
        { "fifth", 2 }, { "sixth", 5 }, { "ssssss", 1 }
    };

    EXPECT_EQ(object_under_test.count_words(text), expected_words);
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

    EXPECT_EQ(object_under_test.count_letters(text), letters_count);
}

TEST_F(Text_manipulator_test, should_count_words_without_slashe)
{
    word_count_col expected_words
    {
        { "main", 4 }, { "CMakeFiles", 3 },
        { "freq_analizer_app", 3 }, { "dir", 3 },
        { "build", 1 }, { "i", 1 }, { "cpp", 1 },
        { "rule", 1 }
    };

    EXPECT_EQ(object_under_test.count_words(text_with_multiple_words_separated_with_slashes), expected_words);
}

TEST_F(Text_manipulator_test, should_count_N_grams)
{
    word_count_col expected_words
    {
        {"co", 3}, {"df", 1}, {"ds", 2}, {"dt", 1},
        {"ec", 3}, {"fi", 6}, {"fo", 5}, {"ft", 2},
        {"hf", 6}, {"hi", 1}, {"hs", 6}, {"if", 2},
        {"ir", 5}, {"ix", 5}, {"nd", 3}, {"on", 3},
        {"ou", 5}, {"rd", 1}, {"rs", 4}, {"rt", 5},
        {"s", 1}, {"se", 3}, {"si", 5}, {"ss", 5},
        {"st", 4}, {"tf", 3}, {"th", 13}, {"ts", 1},
        {"ur", 5}, {"xt", 5}
    };


    EXPECT_EQ(object_under_test.count_N_grams(text, 2), expected_words);
}

}
}
