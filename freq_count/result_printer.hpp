#pragma once

#include "text_manipulator.hpp"

namespace freq_analizer
{
namespace result_printer
{

class IResult_printer
{
public:
    ~IResult_printer() = default;

    virtual void print_words(text_operation::word_count_col const& words) = 0;
    virtual void print_letters(text_operation::letters_count_col const& letters) = 0;
    virtual void print_words_t(text_operation::words_t const& words) = 0;
};

class Result_printer : public IResult_printer
{
public:
    void print_words(text_operation::word_count_col const& words) override;
    void print_letters(text_operation::letters_count_col const& letters) override;
    void print_words_t(text_operation::words_t const& words) override;
};


}
}
