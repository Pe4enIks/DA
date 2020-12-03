#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "pattern_parse.hpp"

void PatternParse(std::vector<unsigned int>& pattern)
{
    char c = '!';
    std::string buf;
    while (true)
    {
        c = getchar();
        if (c == ' ')
        {
            if (!buf.empty()) { pattern.push_back(static_cast<unsigned int>(std::stoi(buf))); }
            buf.clear();
        }
        else if (c == '\n' || c == EOF)
        {
            if (!buf.empty()) { pattern.push_back(static_cast<unsigned int>(std::stoi(buf))); }
            break;
        }
        else { buf.push_back(c); }
    }
}
