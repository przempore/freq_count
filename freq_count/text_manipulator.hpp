#pragma once

#include <map>
#include <vector>
#include <string>

namespace freq_analizer
{
namespace text_operation
{

using words = std::vector<std::string>;
using letters_count_col = std::map<char, unsigned int>;
using word_count_col = std::map<std::string, unsigned int>;

class IText_manipulator
{
public:
    ~IText_manipulator() = default;

    virtual const word_count_col count_words(words const& text) const = 0;
    virtual const letters_count_col count_letters(words const& text) const = 0;
    virtual const word_count_col count_N_grams(words const& text, int const n) const = 0;
};

class Text_manipulator : public IText_manipulator
{
public:
    Text_manipulator()
    {}

    const word_count_col count_words(words const& text) const override;
    const letters_count_col count_letters(words const& text) const override;
    const word_count_col count_N_grams(words const& text, int const n) const override;
};

}
}
