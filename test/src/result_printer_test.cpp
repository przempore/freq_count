#include "gtest/gtest.h"
#include <map>
#include <iostream>
#include "additional_functions.hpp"

namespace freq_analizer
{
namespace result_printer
{


TEST(additional_function_test, should_sort_map)
{
    const std::map<size_t, std::vector<std::string>, std::greater<size_t>> expected_map
    {
        { 1, {"two"} },
        { 2, {"four"} },
        { 3, {"one"} },
        { 5, {"three"} }
    };

//    std::cout << expected_map << std::endl;

}

}
}
