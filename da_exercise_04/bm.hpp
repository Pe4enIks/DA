#pragma once
#include <map>

std::vector<size_t> ZFunc(std::vector<unsigned int>&);
std::vector<size_t> NFunc(std::vector<unsigned int>&);
std::pair<std::vector<size_t>,std::vector<size_t>> LFunctions(std::vector<unsigned int>&);
void BM(std::vector<std::pair<std::pair<size_t, size_t>, unsigned int>> const&, std::vector<unsigned int>&, bool const&);
