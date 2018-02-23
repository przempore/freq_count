#include "gtest/gtest.h"
#include <map>
#include <string>

#include "freq_counter.hpp"
#include "text_manipulator.hpp"
#include "additional_functions.hpp"


using namespace testing;

namespace freq_analizer
{
namespace analizer
{
namespace
{

constexpr float letter1_occurance = 13.f;
constexpr float letter2_occurance = 17.f;
constexpr char check_letter1 = 'f';
constexpr char check_letter2 = 't';
constexpr int ulp = 5;
const std::string n2gram_1 { "th" };
const std::string n2gram_2 { "aa" };
constexpr float n2gram_1_occurance = 4.f;
constexpr float n2gram_2_occurance = 7.f;

const letters_count_col letters_count
{
    {check_letter1, letter1_occurance},
    {check_letter2, letter2_occurance}
};

const n_gram_col n2gram_col
{
    {n2gram_1, n2gram_1_occurance},
    {n2gram_2, n2gram_2_occurance}
};

}

struct Analizer_test : Test
{
    Analizer object_under_test;
};

TEST_F(Analizer_test, should_analize_letter_freq)
{
    float expected_letter1_ratio = letter1_occurance/(letter2_occurance + letter1_occurance);
    float expected_letter2_ratio = letter2_occurance/(letter2_occurance + letter1_occurance);

    auto ret = object_under_test.get_letter_freq(letters_count);

    EXPECT_TRUE(functions::almost_equal(expected_letter1_ratio, ret[check_letter1], ulp));
    EXPECT_TRUE(functions::almost_equal(expected_letter2_ratio, ret[check_letter2], ulp));
}

TEST_F(Analizer_test, should_analize_2gram_freq)
{
    n_gram_freq n_gram;

    EXPECT_EQ(n_gram, object_under_test.get_n_gram_freq(n2gram_col));
}

}
}
