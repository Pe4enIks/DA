#include <iostream>
#include <string>
#include <vector>
#include "bm.hpp"
#include "text_parse.hpp"
#include "pattern_parse.hpp"

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::vector<unsigned int> pattern;
    std::vector<std::pair<std::pair<size_t, size_t>, unsigned int>> text;
    PatternParse(pattern);
    TextParse(text);
    BM(text, pattern, false);
    return 0;
}
