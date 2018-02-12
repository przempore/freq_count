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
};

class Result_printer : public IResult_printer
{
public:
    void print_words(text_operation::word_count_col const& words) override;
};


}
}
