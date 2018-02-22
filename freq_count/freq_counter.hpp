#pragma once

#include <map>


namespace freq_analizer
{
namespace analizer
{

using letters_count_col = std::map<char, unsigned int>;
using letter_freq = std::map<char, float>;

class IAnalizer
{
public:
    ~IAnalizer() = default;

    virtual letter_freq analize_letter_freq(letters_count_col const& letters) = 0;
};


class Analizer : public IAnalizer
{
public:
    letter_freq analize_letter_freq(letters_count_col const& letters) override;
};

}
}
