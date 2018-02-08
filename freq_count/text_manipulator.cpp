#include <text_manipulator.hpp>

namespace freq_analizer
{
namespace text_operation
{

const Word_count_col Text_manipulator::count_words(const std::vector<std::string> &text)
{
    Word_count_col word_count;
    for (auto&& t : text)
    {
        word_count[t]++;
    }

    return word_count;
}

const Letters_count_col Text_manipulator::count_letters(const std::vector<std::string> &text)
{
    return Letters_count_col{};
}



}
}
