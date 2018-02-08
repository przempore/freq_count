#pragma once

#include <map>
#include <vector>
#include <string>

namespace freq_analizer
{
namespace text_operation
{

using Letters_count_col = std::map<char, unsigned int>;
using Word_count_col = std::map<std::string, unsigned int>;

class IText_manipulator
{
public:
    ~IText_manipulator() = default;

    virtual const Word_count_col count_words(std::vector<std::string> const& text) = 0;
    virtual const Letters_count_col count_letters(std::vector<std::string> const& text) = 0;
};

class Text_manipulator : public IText_manipulator
{
public:
    Text_manipulator()
    {}

    const Word_count_col count_words(std::vector<std::string> const& text) override;
    const Letters_count_col count_letters(std::vector<std::string> const& text) override;
};

}
}
