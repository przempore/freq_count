#include <text_manipulator.hpp>
#include <numeric>
#include <iostream>

namespace freq_analizer
{
namespace text_operation
{

const word_count_col Text_manipulator::count_words(words const& text) const
{
    word_count_col word_count;
    for (auto&& t : text)
    {
        word_count[t]++;
    }

    return std::move(word_count);
}

const letters_count_col Text_manipulator::count_letters(words const& text) const
{
    letters_count_col letters_count;

    for (auto&& word : text)
    {
        for (auto&& letter : word)
        {
            letters_count[letter]++;
        }
    }

    return std::move(letters_count);
}

const word_count_col Text_manipulator::count_N_grams(words const& text, const int n) const
{
    word_count_col n_grams_count{};

    std::string s;
    s = std::accumulate(std::begin(text), std::end(text), s);

    for (size_t idx = 0; idx < s.size(); idx++)
    {
        n_grams_count[s.substr(idx, n)]++;
    }

    return std::move(n_grams_count);
}

}
}
