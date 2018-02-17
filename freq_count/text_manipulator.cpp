#include "text_manipulator.hpp"
#include "additional_functions.hpp"
#include <numeric>
#include <iostream>

#include "result_printer.hpp"

namespace freq_analizer
{
namespace text_operation
{

const word_count_col Text_manipulator::count_words(words_t const& text) const
{
    // auto a = functions::cut_string(text[0]);
    // result_printer::Result_printer r_printer;
    // r_printer.print_words_t(a);
    word_count_col word_count;
    for (auto&& t : text)
    {
        word_count[t]++;
    }

    return std::move(word_count);
}

const letters_count_col Text_manipulator::count_letters(words_t const& text) const
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

const word_count_col Text_manipulator::count_N_grams(words_t const& text, const int n) const
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
