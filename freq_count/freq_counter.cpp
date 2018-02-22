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
    for (auto&& a : consts::alphabet)
    {
        if (auto aa = letters.find(a); aa != std::end(letters))
        {
            l_freq[aa->first] = static_cast<float>(aa->second)/letter_count;
            continue;
        }
        l_freq[a] = 0;
    }

    return l_freq;
}

}
}
