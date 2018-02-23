#include <iterator>
#include <iostream>
#include "result_printer.hpp"
#include "additional_functions.hpp"


namespace freq_analizer
{
namespace result_printer
{

using namespace text_operation;
using namespace functions;

void Result_printer::print_words(word_count_col const& words)
{
    std::cout << words << std::endl;
}

void Result_printer::print_letters(const letters_count_col &letters)
{
    std::cout << letters << std::endl;
}

void Result_printer::print_words_t(const words_t &words)
{
    std::cout << words << std::endl;
}


}
}
