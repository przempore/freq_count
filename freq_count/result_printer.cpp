#include <iterator>
#include <iostream>
#include "result_printer.hpp"
#include "additional_functions.hpp"


namespace freq_analizer
{
namespace result_printer
{

using namespace functions;

void Result_printer::print_words(text_operation::word_count_col const & words)
{
    std::cout << words << std::endl;
}

}
}
