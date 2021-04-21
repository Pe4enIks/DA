#include <iostream>
#include <vector>
#include <algorithm>

std::istream& operator>>(std::istream& is, std::vector<std::vector<long long>>& M)
{
    long long n = M.size();
    long long m = M[0].size();
    for(long long i = 0; i < n; ++i)
    {
        for(long long j = 0; j < m; ++j)
        {
            is >> M[i][j];
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<long long>> const& M)
{
    long long n = M.size();
    long long m = M[0].size();
    os << "\n";
    for(long long i = 0; i < n; ++i)
    {
        for(long long j = 0; j < m; ++j)
        {
            os << M[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<std::vector<std::vector<long long>>> const& M)
{
    long long n = M.size();
    long long m = M[0].size();
    os << "\n";
    for(long long i = 0; i < n; ++i)
    {
        for(long long j = 0; j < m; ++j)
        {
            os << "Path: " << M[i][j][0] << " i: " << M[i][j][1] << " j: " << M[i][j][2] << " ";
        }
        os << "\n";
    }
    return os;
}

void GetMinInitLst(std::initializer_list<long long>& ilist, std::vector<std::vector<std::vector<long long>>>& res, std::vector<std::vector<long long>> const& M, long long const& i, long long const& j, bool is_left)
{
    std::initializer_list<long long>::iterator min_el = std::min_element(ilist.begin(), ilist.end());
    res[i][j][0] = *min_el + M[i][j];
    long long ind = min_el - ilist.begin();
    if(is_left) { ++ind; }
    res[i][j][1] = i+2;
    res[i][j][2] = j+ind;
}

void CalcResThree(std::vector<std::vector<std::vector<long long>>>& res, std::vector<std::vector<long long>> const& M, long long const& i, long long const& j)
{
    std::initializer_list<long long> ilist = {res[i+1][j-1][0], res[i+1][j][0], res[i+1][j+1][0]};
    GetMinInitLst(ilist, res, M, i, j, false);
}

void CalcResTwoLeft(std::vector<std::vector<std::vector<long long>>>& res, std::vector<std::vector<long long>> const& M, long long const& i, long long const& j)
{
    std::initializer_list<long long> ilist = {res[i+1][j][0], res[i+1][j+1][0]};
    GetMinInitLst(ilist, res, M, i, j, true);
}

void CalcResTwoRight(std::vector<std::vector<std::vector<long long>>>& res, std::vector<std::vector<long long>> const& M, long long const& i, long long const& j)
{
    std::initializer_list<long long> ilist = {res[i+1][j-1][0], res[i+1][j][0]};
    GetMinInitLst(ilist, res, M, i, j, false);
}

void CalcRes(char const& flag, std::vector<std::vector<std::vector<long long>>>& res, std::vector<std::vector<long long>> const& M, long long const& i, long long const& j)
{
    if(flag == 't') { CalcResThree(res, M, i, j); }
    else if(flag == 'l') { CalcResTwoLeft(res, M, i, j); }
    else if(flag == 'r') { CalcResTwoRight(res, M, i, j); }
}

std::vector<long long> GetMinVct(std::vector<std::vector<std::vector<long long>>> const& res, long long const& n, long long const& m)
{
    std::vector<long long> min_vct;
    long long cur_min_ind_i = 1;
    long long cur_min_ind_j = 1;
    long long min = res[0][0][0];
    long long min_ind_j = 1;
    long long min_ind_i = 1;
    for(long long i = 1; i < m; ++i)
    {
        if(res[0][i][0] < min)
        {
            min_ind_j = i+1;
            min = res[0][i][0];
        }
    }
    min_vct.push_back(min);
    for(long long i = 0; i < n; ++i)
    {
        min_vct.push_back(min_ind_i);
        min_vct.push_back(min_ind_j);
        cur_min_ind_i = res[min_ind_i-1][min_ind_j-1][1];
        cur_min_ind_j = res[min_ind_i-1][min_ind_j-1][2];
        min_ind_i = cur_min_ind_i;
        min_ind_j = cur_min_ind_j;
    }
    return min_vct;
}

std::vector<long long> GetRes(std::vector<std::vector<long long>> const& M, long long const& n, long long const& m)
{
    char flag = '0';
    std::vector<std::vector<std::vector<long long>>> res(n, std::vector<std::vector<long long>>(m, std::vector<long long>(3, 0)));
    for(long long j = 0; j < m; ++j) { res[n-1][j][0] = M[n-1][j]; }
    for(long long i = n - 2; i >= 0; --i)
    {
        for(long long j = 0; j < m; ++j)
        {
            if(j == 0) { flag = 'l'; }
            else if(j == m-1) {flag = 'r'; }
            else { flag = 't'; }
            CalcRes(flag, res, M, i, j);
        }
    }
    return GetMinVct(res, n, m);
}

int main()
{
    long long n = 0;
    long long m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<long long>> M(n, std::vector<long long>(m, 0));
    std::cin >> M;
    std::vector<long long> result = GetRes(M, n, m);
    std::cout << result[0] << "\n";
    for(long long i = 1; i <= result.size() - 1; i += 2)
    {
        std::cout << "(" << result[i] << "," << result[i+1] << ") ";
    }
    std::cout << "\n";
    return 0;
}
