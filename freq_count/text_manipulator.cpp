#include "text_manipulator.hpp"
#include "additional_functions.hpp"
#include <numeric>
#include <iostream>

#include "result_printer.hpp"

// todo: try to remove copy vector like this -> auto words = strip_unicode_in_vector(text);


namespace
{
std::string const delimeter {"/.-$()@:=#&\"\\!"};
}

namespace freq_analizer
{
namespace text_operation
{

const word_count_col Text_manipulator::count_words(words_t const& text)
{
    auto words = strip_unicode_in_vector(text);
    word_count_col word_count;
    for (auto&& w : words)
    {
        if (auto out = cut_string_if_needed(w, delimeter); not out.empty())
        {
            fill_word_count_col(out, word_count);
            continue;
        }
        word_count[w]++;
    }

    return word_count;
}

const letters_count_col Text_manipulator::count_letters(words_t const& text)
{
    auto words = strip_unicode_in_vector(text);

    letters_count_col letters_count;

    for (auto&& word : words)
    {
        for (auto&& letter : word)
        {
            letters_count[letter]++;
        }
    }

    return letters_count;
}

const word_count_col Text_manipulator::count_N_grams(words_t const& text, int n)
{
    auto words = strip_unicode_in_vector(text);

    word_count_col n_grams_count{};

    std::string s;
    s = std::accumulate(std::begin(words), std::end(words), s);

    for (size_t idx = 0; idx < s.size(); idx++)
    {
        n_grams_count[s.substr(idx, n)]++;
    }

    return n_grams_count;
}

bool Text_manipulator::should_cut_string(std::string const& s_to_cut, std::string const& s_to_find) const
{
    return std::string::npos != s_to_cut.find_first_of(s_to_find);
}

words_t Text_manipulator::cut_string_if_needed(std::string const& s_to_cut, const std::string &delimeter)
{
    if (not should_cut_string(s_to_cut, delimeter))
    {
        return words_t{};
    }

    auto cutted_string = functions::cut_string(s_to_cut, delimeter);
    return cutted_string;
}

void Text_manipulator::fill_word_count_col(words_t const& text, word_count_col& word_count)
{
    for (auto&& t : text)
    {
        word_count[t]++;
    }
}

void Text_manipulator::strip_unicode(std::string& str)
{
    str.erase(std::remove_if(std::begin(str), std::end(str), [](auto&& c) { return not(c >= 0 and c < 128); }), std::end(str));
}

words_t Text_manipulator::strip_unicode_in_vector(words_t const& words)
{
    auto text = words;
    for (auto&& word : text)
    {
        strip_unicode(word);
    }

    return text;
}

}
}
