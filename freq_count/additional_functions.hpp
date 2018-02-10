#pragma once

#include <map>
#include <vector>
#include <string>


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

}
}
