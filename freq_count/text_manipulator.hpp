#pragma once

#include <map>
#include <vector>
#include <string>

namespace freq_analizer
{
namespace text_operation
{

using words_t = std::vector<std::string>;
using letters_count_col = std::map<char, unsigned int>;
using word_count_col = std::map<std::string, unsigned int>;

class IText_manipulator
{
public:
    ~IText_manipulator() = default;

    virtual const word_count_col count_words(words_t const& text) = 0;
    virtual const letters_count_col count_letters(words_t const& text) = 0;
    virtual const word_count_col count_N_grams(words_t const& text, int n) = 0;
};

class Text_manipulator : public IText_manipulator
{
public:
    Text_manipulator()
    {}

    const word_count_col count_words(words_t const& text) override;
    const letters_count_col count_letters(words_t const& text) override;
    const word_count_col count_N_grams(words_t const& text, int n) override;

private:
    bool should_cut_string(std::string const& s_to_cut, std::string const& s_to_find) const;
    words_t cut_string_if_needed(std::string const& s_to_cut, std::string const& delimeter);
    void fill_word_count_col(const words_t &text, word_count_col& word_count);
    void strip_unicode(std::string& str);
    words_t strip_unicode_in_vector(words_t const& words);
};

}
}
