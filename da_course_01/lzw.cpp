#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <chrono>

std::pair<std::unordered_map<std::string, size_t>, size_t> init_dict_for_compress()
{
    std::unordered_map<std::string, size_t> m;
    size_t ind = 1;
    for(char symb = 'a'; symb <= 'z'; ++symb)
    {
        std::string s(sizeof(char), symb);
        m[s] = ind;
        ++ind;
    }
    std::string space(sizeof(char), ' ');
    m[space] = ind;
    ++ind;
    return std::pair(m, ind);
}

std::pair<std::unordered_map<size_t, std::string>, size_t> init_dict_for_decompress()
{
    std::unordered_map<size_t, std::string> m;
    size_t ind = 1;
    for(char symb = 'a'; symb <= 'z'; ++symb)
    {
        std::string s(sizeof(char), symb);
        m[ind] = s;
        ++ind;
    }
    std::string space(sizeof(char), ' ');
    m[ind] = space;
    ++ind;
    return std::pair(m, ind);
}

std::pair<std::vector<size_t>, size_t> compress()
{
    std::pair<std::unordered_map<std::string, size_t>, size_t> dict = init_dict_for_compress();
    std::vector<size_t> res;
    std::string p = "";
    size_t count = 0;
    char c = '0';
    while(std::cin.get(c))
    {
        ++count;
        if(dict.first.find(p+c) != dict.first.end())
            p += c;
        else
        {
            res.push_back(dict.first[p]);
            dict.first[p+c] = dict.second;
            ++dict.second;
            p = c;
        }
    }
    std::pair<std::vector<size_t>, size_t> result(res, count);
    return result;
}

std::string decompress(std::vector<size_t> const& vct)
{
    std::pair<std::unordered_map<size_t, std::string>, size_t> dict = init_dict_for_decompress();
    size_t prev = vct[0];
    size_t cw;
    std::string res = dict.first[prev];
    std::string c = "";
    c += res[0];
    std::string out = res;
    for(size_t i = 0; i < vct.size()-1; ++i)
    {
        cw = vct[i+1];
        if(dict.first.count(cw) == 0)
        {
            res = dict.first[prev];
            res += c;
        }
        else
            res = dict.first[cw];
        out += res;
        c = "";
        c += res[0];
        dict.first[dict.second] = dict.first[prev] + c;
        ++dict.second;
        prev = cw;
    }
    return out;
}

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    uint64_t compress_time = 0;
    uint64_t decompress_time = 0;
    start = std::chrono::system_clock::now();
    std::pair<std::vector<size_t>, size_t> res = compress();
    end = std::chrono::system_clock::now();
    double comp_size = res.first.size();
    double text_size = res.second;
    compress_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Compressed file:\n";
    for(auto& el: res.first)
        std::cout << el << " ";
    std::cout << "\n";
    std::cout << "Decompressed vector:\n";
    start = std::chrono::system_clock::now();
    std::cout << decompress(res.first) << "\n";
    end = std::chrono::system_clock::now();
    decompress_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "Compress time: " << compress_time << " microseconds\n";
    std::cout << "Decompress time: " << decompress_time << " microseconds\n";
    std::cout << "Compress coefficient: " << comp_size / text_size << "\n";
    return 0;
}
