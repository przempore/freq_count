#include "freq_counter.hpp"

#include <iostream>
#include "consts.hpp"


namespace freq_analizer
{
namespace analizer
{

letter_freq Analizer::analize_letter_freq(letters_count_col const& letters)
{
    int letter_count = 0;
    for (auto&& [letter, count] : letters)
    {
        letter_count += count;
    }

    letter_freq l_freq;
    for (auto&& letter : consts::alphabet)
    {
        if (auto found_letter = letters.find(letter); found_letter != std::end(letters))
        {
            l_freq[found_letter->first] = found_letter->second/letter_count;
            continue;
        }
        l_freq[letter] = 0.f;
    }

    return l_freq;
}

}
}
