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
auto sort_map(std::map<T, size_t> const& unsorted_map)
{
    std::map<size_t, std::vector<T>, std::greater<size_t>> sorted_map;

    for (auto&& [str, frq] : unsorted_map)
    {
        sorted_map[frq].emplace_back(str);
    }

    return std::move(sorted_map);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, std::vector<T> const& v)
{
    if (v.empty())
    {
        return out;
    }

    out << '[';
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";

    return out;
}

template <typename T, typename U>
std::ostream& operator<< (std::ostream& out, std::pair<T, U> const& p)
{
    out << '<' << p.first << ", " << p.second << ">";
    return out;
}


template <typename T, typename U>
std::ostream& operator<< (std::ostream& out, std::map<T, U> const& map_to_print)
{
    if (map_to_print.empty())
    {
        return out;
    }

    out << '[';
    for (auto&& m : map_to_print)
    {
        out << m << "\n";
    }

    out << "\b\b]";

    return out;
}

}
}
