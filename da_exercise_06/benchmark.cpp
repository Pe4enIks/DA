#include <iostream>
#include <chrono>
#include "bigint.hpp"
#include <gmpxx.h>


int main()
{
    uint64_t bigint_time = 0;
	uint64_t gmp_time = 0;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    NBigInt::TBigInt num1("10000000000000"), num2("12912912927376274372");
    NBigInt::TBigInt num3("4");
    NBigInt::TBigInt bigint_res;
    mpz_class gpm_num1;
    mpz_class gpm_num2;
    mpz_class gpm_num3;
    mpz_class gpm_res;
    gpm_num1 = "10000000000000";
    gpm_num2 = "12912912927376274372";
    gpm_num3 = "4";
    //сумма
    int n_sum = 100000000;
    start = std::chrono::system_clock::now();
    for(int i = 0; i < n_sum; ++i)
    {
        bigint_res = num1 + num2;
    }
    end = std::chrono::system_clock::now();
    bigint_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    start = std::chrono::system_clock::now();
    for(int i = 0; i < n_sum; ++i)
    {
        gpm_res = gpm_num1 + gpm_num2;
    }
    end = std::chrono::system_clock::now();
    gmp_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Bigint sum time: " << (double)bigint_time/1000000000 << " seconds\n";
    std::cout << "Gmp sum time: " << (double)gmp_time/1000000000 << " seconds\n";
    //разность
    int n_sub = 100000000;
    start = std::chrono::system_clock::now();
    for(int i = 0; i < n_sub; ++i)
    {
        bigint_res = num2 - num1;
    }
    end = std::chrono::system_clock::now();
    bigint_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    start = std::chrono::system_clock::now();
    for(int i = 0; i < n_sub; ++i)
    {
        gpm_res = gpm_num2 - gpm_num1;
    }
    end = std::chrono::system_clock::now();
    gmp_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "\nBigint sub time: " << (double)bigint_time/1000000000 << " seconds\n";
    std::cout << "Gmp sub time: " << (double)gmp_time/1000000000 << " seconds\n";
    //умножение
    int n_mult = 100000000;
    start = std::chrono::system_clock::now();
    for(int i = 0; i < n_mult; ++i)
    {
        bigint_res = num2 * num1;
    }
    end = std::chrono::system_clock::now();
    bigint_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    start = std::chrono::system_clock::now();
    for(int i = 0; i < n_mult; ++i)
    {
        gpm_res = gpm_num2 * gpm_num1;
    }
    end = std::chrono::system_clock::now();
    gmp_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "\nBigint mult time: " << (double)bigint_time/1000000000 << " seconds\n";
    std::cout << "Gmp mult time: " << (double)gmp_time/1000000000 << " seconds\n";
    return 0;
}
