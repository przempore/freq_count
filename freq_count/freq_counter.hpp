#pragma once

#include <map>
#include <string>


namespace freq_analizer
{
namespace analizer
{

using letters_count_col = std::map<char, float>;
using letter_freq = std::map<char, float>;
using n_gram_col = std::map<std::string, float>;
using n_gram_freq = std::map<std::string, float>;

class IAnalizer
{
public:
    ~IAnalizer() = default;

    virtual letter_freq get_letter_freq(letters_count_col const& letters) = 0;
    virtual n_gram_freq get_n_gram_freq(n_gram_col const& n_gram) = 0;
};


class Analizer : public IAnalizer
{
public:
    letter_freq get_letter_freq(letters_count_col const& letters) override;
    n_gram_freq get_n_gram_freq(n_gram_col const& n_gram) override;
};

}
}
