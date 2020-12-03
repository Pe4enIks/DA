#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include "bm.hpp"

std::vector<size_t> ZFunc(std::vector<unsigned int>& pattern)
{
	size_t n = pattern.size();
	std::vector<size_t> z(n);
	for (size_t i=1, l=0, r=0; i<n; ++i)
    {
		if (i <= r) { z[i] = std::min(r-i+1, z[i-l]); }
		while (i+z[i] < n && pattern[z[i]] == pattern[i+z[i]]) { ++z[i]; }
		if (i+z[i]-1 > r) { l = i,  r = i+z[i]-1; }
	}
	return z;
}

std::vector<size_t> NFunc(std::vector<unsigned int>& pattern)
{
    std::reverse(pattern.begin(), pattern.end());
    std::vector<size_t> z = ZFunc(pattern);
    std::vector<size_t> n(z.size());
    for(size_t i = 0; i < pattern.size(); ++i) { n[i] = z[pattern.size()-i-1]; }
    std::reverse(pattern.begin(), pattern.end());
    return n;
}

std::pair<std::vector<size_t>,std::vector<size_t>> LFunctions(std::vector<unsigned int>& pattern)
{
    std::vector<size_t> n = NFunc(pattern);
    std::vector<size_t> l(n.size());
    std::vector<size_t> L(pattern.size()+1);
    size_t j = 0;
    for(size_t i = 0; i < pattern.size()-1; ++i)
    {
        if(n[i] != 0)
        {
            j = pattern.size()-n[i];
            l[j] = i;
        }
        if(n[i] == i+1) { L[pattern.size()-i-1] = i+1; }
        else { L[pattern.size()-i-1] = L[pattern.size()-i]; }
    }
    return std::pair<std::vector<size_t>,std::vector<size_t>>(l,L);
}


void BM(std::vector<std::pair<std::pair<size_t, size_t>, unsigned int>> const& text, std::vector<unsigned int>& pattern, bool const& benchmark_flag)
{
    int k = pattern.size() - 1;
    std::vector<int> entry;
    std::pair<std::vector<size_t>, std::vector<size_t>> l_funcs = LFunctions(pattern);
    while (k < text.size())
    {
        int i = pattern.size() - 1;
        int j = k;
        while ((i >= 0) && (pattern[i] == text[j].second))
        {
            --i;
            --j;
        }
        if (i == -1)
        {
            entry.push_back(k-pattern.size()+1);
            if (pattern.size() > 2) { k += pattern.size() - l_funcs.second[1]; } else { ++k; }
        }
        else
        {
            int maxsuff = 1;
            int maxsymb = 1;
            if (i == pattern.size() - 1) { maxsuff = 1; }
            else
            {
                if (l_funcs.first[i + 1] > 0) {  maxsuff = pattern.size() - l_funcs.first[i + 1] - 1; }
                else { maxsuff = pattern.size() - l_funcs.second[i + 1]; }
            }
            k += std::max(maxsuff, maxsymb);
        }
    }
    if(!benchmark_flag) {for(size_t i = 0; i < entry.size(); ++i) { std::cout << text[entry[i]].first.first << "," << text[entry[i]].first.second << "\n"; } }
}
