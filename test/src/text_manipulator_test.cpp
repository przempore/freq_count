#include "gtest/gtest.h"
#include "text_manipulator.hpp"
#include <vector>
#include <string>

using namespace ::testing;

namespace
{

freq_analizer::text_operation::words_t text
{
    "first", "dddddd", "dddddd"
};

freq_analizer::text_operation::words_t text_with_multiple_words_separated_with_slashes
{
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
        { "first", 1 }, { "dddddd", 2 }
    };

    EXPECT_EQ(object_under_test.count_words(text), expected_words);
}

TEST_F(Text_manipulator_test, should_count_letters)
{
    letters_count_col letters_count
    {
        {'f', 1}, {'i', 1}, {'t', 1},
        {'s', 1}, {'r', 1}, {'d', 12},
    };

    EXPECT_EQ(object_under_test.count_letters(text), letters_count);
}

TEST_F(Text_manipulator_test, should_count_words_without_slashe)
{
    word_count_col expected_words
    {
        { "main", 3 }, { "CMakeFiles", 2 }, { "dir", 2 },
        { "freq_analizer_app", 2 }, { "i", 1 }, { "cpp", 1 },
        { "rule", 1 }
    };

    EXPECT_EQ(object_under_test.count_words(text_with_multiple_words_separated_with_slashes), expected_words);
}

TEST_F(Text_manipulator_test, should_count_1grams)
{
    word_count_col letters_count
    {
        {"f", 1}, {"i", 1}, {"t", 1},
        {"s", 1}, {"r", 1}, {"d", 12},
    };

    EXPECT_EQ(object_under_test.count_N_grams(text, 1), letters_count);
}

TEST_F(Text_manipulator_test, should_count_2grams)
{
    word_count_col expected_words
    {
        { "d", 1 }, { "dd", 11 }, { "fi", 1 }, { "ir", 1 },
        { "rs", 1 }, { "st", 1 }, { "td", 1 }
    };

    EXPECT_EQ(object_under_test.count_N_grams(text, 2), expected_words);
}

}
}
