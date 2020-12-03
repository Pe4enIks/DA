#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "bm.hpp"
#include "text_parse.hpp"
#include "pattern_parse.hpp"

int count_of_substrings(std::string& src, std::string& sub)
{
    int start = 0;
    int count = 0;
    int pos = 0;
    while(true)
    {
        pos = src.find(sub.c_str(),start);
        if (pos != -1)
        {
            start = pos + sub.size();
            count++;
        } else { break; }
    }
    return count;
}

int main()
{
    std::ifstream finp1("C:\\Users\\SuperPC\\Downloads\\VSC\\DA\\da_exercise_04\\banchmark_bad.txt");
    std::chrono::time_point<std::chrono::system_clock> start, end;
    uint64_t my_time = 0;
	uint64_t time = 0;
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::vector<unsigned int> pattern;
    std::vector<std::pair<std::pair<size_t, size_t>, unsigned int>> text;
    std::string pat;
    std::string t;
    std::string cur_str;
    start = std::chrono::system_clock::now();
    std::getline(finp1, pat);
    while(finp1 >> cur_str){ t += cur_str; }
    count_of_substrings(t, pat);
    end = std::chrono::system_clock::now();
    time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "C++ find: " << (double)time/1000000000 << " seconds\n";
    start = std::chrono::system_clock::now();
    PatternParse(pattern);
    TextParse(text);
    BM(text, pattern, true);
    end = std::chrono::system_clock::now();
    my_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "My BM: " << (double)my_time/1000000000 << " seconds\n";
    return 0;
}
