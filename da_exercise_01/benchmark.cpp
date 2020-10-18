#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>
#include "structs.hpp"
#include "my_vector.hpp"
#include "radix_sort.hpp"

using duration_t = std::chrono::milliseconds;
const std::string DURATION_PREFIX = "ms";

bool comp(const TPair& lhs, const TPair& rhs) 
{
    if (lhs.key_[2] == rhs.key_[2]) 
    {
        if (lhs.key_[1] == rhs.key_[1]) 
        {
            return (lhs.key_[0].c_str()[0] - 'A') < (rhs.key_[0].c_str()[0] - 'A');
        }
        return (100*(lhs.key_[1].c_str()[0]-'0')+10*(lhs.key_[1].c_str()[1]-'0')+(lhs.key_[1].c_str()[2]-'0')) < (100*(rhs.key_[1].c_str()[0]-'0')+10*(rhs.key_[1].c_str()[1]-'0')+(rhs.key_[1].c_str()[2]-'0'));
    }
    return (50*lhs.key_[2].c_str()[0]+lhs.key_[2].c_str()[1]-'A'-'A') < (50*rhs.key_[2].c_str()[0]+rhs.key_[2].c_str()[1]-'A'-'A');
}
int main()
{
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    TVector<TPair> vec(10); 
    TUll val;
    size_t max_1 = 0;
    size_t max_2 = 0;
    size_t max_3 = 0;
    std::string key_0;
    std::string key_1;
    std::string key_2;
    size_t tmp_max_1 = 0;
    size_t tmp_max_2 = 0;
    size_t tmp_max_3 = 0;

    while(std::cin>>key_0>>key_1>>key_2>>val)
    {
        tmp_max_1 = key_0.c_str()[0] - 'A';
        tmp_max_2 = (100*(key_1.c_str()[0]-'0')+10*(key_1.c_str()[1]-'0')+(key_1.c_str()[2]-'0'));
        tmp_max_3 = (50*key_2.c_str()[0]+key_2.c_str()[1]-'A'-'A');
        max_1 = max_1 < tmp_max_1 ? tmp_max_1 : max_1;
        max_2 = max_2 < tmp_max_2 ? tmp_max_2 : max_2;
        max_3 = max_3 < tmp_max_3 ? tmp_max_3 : max_3; 
        TPair elem(key_0, key_1, key_2, val);
        vec.PushBack(elem);
    }   
    TVector<TPair> input_stl = vec;
    std::cout << "Count of lines is " << vec.Size() << std::endl;

    // Измеряем время работы поразрядной сортировки.
    std::chrono::time_point<std::chrono::system_clock> start_ts = std::chrono::system_clock::now();
    RadixSort(vec, max_1, max_2, max_3);
    auto end_ts = std::chrono::system_clock::now();
    uint64_t counting_sort_ts = std::chrono::duration_cast<duration_t>( end_ts - start_ts ).count();

    // Измеряем время работы stl сортировки.
    start_ts = std::chrono::system_clock::now();
    std::stable_sort(&input_stl[0], &input_stl[1000000], comp);
    end_ts = std::chrono::system_clock::now();

    uint64_t stl_sort_ts = std::chrono::duration_cast<duration_t>( end_ts - start_ts ).count();
    std::cout << "Radix sort time: " << counting_sort_ts << DURATION_PREFIX << std::endl;
    std::cout << "STL stable sort time: " << stl_sort_ts << DURATION_PREFIX << std::endl;
}