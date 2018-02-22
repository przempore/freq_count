#pragma once

#include <vector>
#include <string>


namespace freq_analizer
{
namespace consts
{

const std::vector<std::pair<char, float>> english_freq
                                        { {'a', 8.167f},
                                          {'b', 1.492f},
                                          {'c', 2.782f},
                                          {'d', 4.253f},
                                          {'e', 12.702f},
                                          {'f', 2.228f},
                                          {'g', 2.015f},
                                          {'h', 6.094f},
                                          {'i', 6.966f},
                                          {'j', 0.153f},
                                          {'k', 0.772f},
                                          {'l', 4.025f},
                                          {'m', 2.406f},
                                          {'n', 6.749f},
                                          {'o', 7.507f},
                                          {'p', 1.929f},
                                          {'q', 0.095f},
                                          {'r', 5.987f},
                                          {'s', 6.327f},
                                          {'t', 9.056f},
                                          {'u', 2.758f},
                                          {'v', 0.978f},
                                          {'w', 2.360f},
                                          {'x', 0.150f},
                                          {'y', 1.974f},
                                          {'z', 0.074f} };

const std::string alphabet {"abcdefghijklmnopqrstuwxyz"};

enum class error_causes
{
    success,
    too_few_arguments,
    calcuation_went_wrong
};

}
}
