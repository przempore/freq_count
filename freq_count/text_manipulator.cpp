#include <text_manipulator.hpp>

namespace freq_analizer
{
namespace text_operation
{

const word_count_col Text_manipulator::count_words(words const& text)
{
    word_count_col word_count;
    for (auto&& t : text)
    {
        word_count[t]++;
    }

    return word_count;
}

const letters_count_col Text_manipulator::count_letters(words const& text)
{
    letters_count_col letters_count;

    for (auto&& word : text)
    {
        for (auto&& letter : word)
        {
            letters_count[letter]++;
        }
    }

    return letters_count;
}



}
}
