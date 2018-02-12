#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>


namespace freq_analizer
{
namespace functions
{

template<typename T>
const auto sort_map(std::map<T, size_t> const& unsorted_map)
{
    std::map<size_t, std::vector<T>, std::greater<size_t>> sorted_map;

    for (auto&& [str, frq] : unsorted_map)
    {
        sorted_map[frq].emplace_back(str);
    }

    return sorted_map;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v)
{
    if (v.empty())
    {
        return out;
    }

//    out << " [";
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";

    return out;
}

}
}
