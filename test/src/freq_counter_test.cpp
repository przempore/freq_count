#include "gtest/gtest.h"
#include <map>
#include <string>

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

n_gram_col n2gram_col
{
    {"th", 4}, {"aa", 7}
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
        {'f', expected_f_ratio}, {'t', expected_t_ratio}
    };

    EXPECT_EQ(expected_freq, object_under_test.get_letter_freq(letters_count));
}

TEST_F(Analizer_test, should_analize_2gram_freq)
{
    n_gram_freq n_gram;

    EXPECT_EQ(n_gram, object_under_test.get_n_gram_freq(n2gram_col));
}

}
}
