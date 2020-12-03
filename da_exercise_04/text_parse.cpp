#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "text_parse.hpp"

void TextParse(std::vector<std::pair<std::pair<size_t,size_t>, unsigned int>>& text)
{
    char c = '!';
    int row = 1;
    int col = 1;
    std::string buf;
    bool ispace = false;
    while((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if(!buf.empty()) { text.push_back({{row, col}, static_cast<unsigned int>(std::stoi(buf))}); }
            if(!ispace)
            {
                ispace = true;
                ++col;
            }
            buf.clear();
        }
        else if (c == '\n')
        {
            if (!buf.empty()) { text.push_back({{row, col}, static_cast<unsigned int>(std::stoi(buf))}); }
            buf.clear();
            ispace = false;
            col = 1;
            ++row;
        }
        else
        {
            ispace = false;
            buf.push_back(c);
        }
    }
}
