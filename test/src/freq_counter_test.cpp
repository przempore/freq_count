#include "gtest/gtest.h"
#include <map>

#include "freq_counter.hpp"
#include "text_manipulator.hpp"


using namespace testing;

namespace freq_analizer
{
namespace analizer
{
namespace
{

letters_count_col letters_count
{
    {'t', 17}, {'f', 13}, {'h', 13}, {'i', 12},
    {'s', 18}, {'r', 10}, {'o', 8}, {'u', 5},
    {'x', 5}, {'d', 4}, {'c', 3}, {'e', 3},
    {'n', 3}
};

}

struct Analizer_test : Test
{
    Analizer object_under_test;
};

TEST_F(Analizer_test, should_analize_letter_freq)
{
    letter_freq expected_freq
    {
        {'a', 0}, {'b', 0}, {'c', 3}, {'d', 4}, {'e', 3}, {'f', 13}, {'g', 0}, {'h', 13},
        {'i', 12}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 3}, {'o', 8}, {'p', 0},
        {'q', 0}, {'r', 10}, {'s', 18}, {'t', 17}, {'u', 5}, {'v', 0}, {'w', 0},
        {'x', 5}, {'y', 0}, {'z', 0}
    };

    EXPECT_EQ(expected_freq, object_under_test.analize_letter_freq(letters_count));
}

}
}
