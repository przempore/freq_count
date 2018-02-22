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

const float f_occurance = 13.f;
const float t_occurance = 17.f;

letters_count_col letters_count
{
    {'f', f_occurance}, {'t', t_occurance}
};

}

struct Analizer_test : Test
{
    Analizer object_under_test;
};

TEST_F(Analizer_test, should_analize_letter_freq)
{
    float expected_f_ratio = f_occurance/(t_occurance + f_occurance);
    float expected_t_ratio = t_occurance/(t_occurance + f_occurance);

    letter_freq expected_freq
    {
        {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', expected_f_ratio}, {'g', 0}, {'h', 0},
        {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0},
        {'q', 0}, {'r', 0}, {'s', 0}, {'t', expected_t_ratio}, {'u', 0}, {'v', 0}, {'w', 0},
        {'x', 0}, {'y', 0}, {'z', 0}
    };




    EXPECT_EQ(expected_freq, object_under_test.analize_letter_freq(letters_count));
}

}
}
