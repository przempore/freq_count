#include "additional_functions.hpp"

namespace freq_analizer
{
namespace functions
{

std::vector<std::string> cut_string(const std::string &input, const std::string &delim)
{
    std::string line(input);
    std::vector<std::string> strs;
    boost::split(strs, line, boost::is_any_of(delim));

    return strs;
}



}
}
