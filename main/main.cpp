#include <iostream>
#include <vector>
#include "consts.hpp"
#include "file_operator.hpp"
#include "text_manipulator.hpp"
#include "result_printer.hpp"

namespace freq_analizer
{

using namespace consts;
using file_readers = std::vector<file_operation::File_reader>;

error_causes print_help(char* filename)
{
    std::cout << "Usage: " << filename << " <file_name>" << std::endl;
    return error_causes::too_few_arguments;
}

file_readers create_file_readers_with_files(int argc, char* argv[])
{
    using namespace file_operation;
    file_readers files_readers {};

    for (size_t file_idx = 1; file_idx < argc; file_idx++)
    {
        File_reader file_operation(argv[file_idx]);
        files_readers.push_back(file_operation);
    }

    return files_readers;
}

void count_letters_in_files(file_readers f_readers)
{
    result_printer::Result_printer res_print;
    using namespace text_operation;
    text_operation::Text_manipulator text_manipulator;
    std::vector<letters_count_col> letters_col;
    std::vector<word_count_col> words_col;
    for (auto&& fr : f_readers)
    {
        letters_col.push_back(text_manipulator.count_letters(fr.get_file_content()));
        words_col.push_back(text_manipulator.count_words(fr.get_file_content()));
    }
    res_print.print_letters(letters_col[0]);
    res_print.print_words(words_col[0]);
}

error_causes calculate_freq(int argc, char* argv[])
{
    using namespace file_operation;

    auto f_readers = create_file_readers_with_files(argc, argv);

    count_letters_in_files(f_readers);

    return error_causes::success;
}

} // namespace freq_analizer


int main(int argc, char* argv[])
{
    using namespace freq_analizer;
    if (argc < 2)
    {
        print_help(argv[0]);

        return 1;
    }

    if (calculate_freq(argc, argv) != consts::error_causes::success)
    {
        return 2;
    }

    return 0;
}












//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <unordered_set>
//#include <iterator>
//#include <map>
//#include <string_view>
//#include <algorithm>
//#include <numeric>

//using namespace std;

//class Letter_pair_n
//{
//public:
//    Letter_pair_n(fstream& file)
//    {
//        fill_str_vec(file);
//        m_text = accumulate(begin(m_str_vec), end(m_str_vec), m_text);
//    }

//private:
//    void fill_str_vec(fstream& file)
//    {
//        m_str_vec.reserve(200);
//        string str;
//        while (file >> str)
//        {
//            m_str_vec.push_back(str);
//            for (auto&& letter : str)
//            {
//                m_letters_count[letter]++;
//            }
//        }
//    }
//    auto calculate_sorted_letters_count()
//    {
//        map<int, vector<char>, greater<int>> sorted_letters_count;
//        for(auto&& [word, frq] : m_letters_count)
//        {
//            sorted_letters_count[frq].emplace_back(word);
//        }

//        return sorted_letters_count;
//    }

//    auto calculate_N_letters_count(size_t n)
//    {
//        const size_t letter_pair_count = m_text.size() / n;
//        vector<string> letter_pairs;
//        letter_pairs.reserve(letter_pair_count);

//        for (size_t letter_pair = 0; letter_pair < letter_pair_count; letter_pair+=n)
//        {
//            string sub_string = m_text.substr(letter_pair, n);
//            letter_pairs.push_back(sub_string);
//        }
//        map<string, int> pair_letters_count;
//        for (auto&& lp : letter_pairs)
//        {
//            pair_letters_count[lp]++;
//        }

//        map<int, vector<string>, greater<int>> sorted_N_letters_count;
//        for(auto&& [word, frq] : pair_letters_count)
//        {
//            sorted_N_letters_count[frq].emplace_back(word);
//        }
//        return sorted_N_letters_count;
//    }

//    auto find_repeated_letters(size_t n)
//    {
//        return 0;
//    }

//public:
//    auto get_N_letters_count(size_t n)
//    {
//        return calculate_N_letters_count(n);
//    }

//    auto get_sorted_letter_count()
//    {
//        return calculate_sorted_letters_count();
//    }

//private:
//    vector<string> m_str_vec;
//    map<char, int> m_letters_count;
//    string m_text;
//};

//void print_letters_count(auto letters_count)
//{
//    for (auto&& [count, letters] : letters_count)
//    {
//        cout << count << ": ";
//        for (auto&& letter : letters)
//        {
//            cout << letter << "|";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

//void calculate_letters_count(fstream& file)
//{
//    Letter_pair_n letter_pair_n(file);

//    auto letters_count = letter_pair_n.get_sorted_letter_count();
//    print_letters_count(letters_count);

//    for (size_t pairN = 2; pairN < 6; pairN++)
//    {
//        auto letters_count_N2 = letter_pair_n.get_N_letters_count(pairN);
//        print_letters_count(letters_count_N2);
//    }
//}

//bool count_letters_in_file(std::string file_path)
//{
//    fstream file (file_path);
//    if (not file)
//    {
//        cout << "Can't open file!" << endl;
//        return false;
//    }

//    calculate_letters_count(file);

//    return true;
//}

//int print_help()
//{
//    cout << "Usage: freq_count <file_n>" << endl;
//    return 1;
//}

//bool calculate_freq(int file_count, char* file_path[])
//{
//    for (int file = 1; file < file_count; file++)
//    {
//        cout << "===============================" << file_path[file] << "===============================" << endl;
//        if (not count_letters_in_file(file_path[file])) return false;
//    }

//    return true;
//}

//int main(int argc, char* argv[])
//{
//    if (argc < 2)
//    {
//        return print_help();
//    }

//    if (not calculate_freq(argc, argv)) return 1;

//    return 0;
//}
