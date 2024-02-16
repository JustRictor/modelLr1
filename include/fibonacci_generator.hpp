#ifndef __FIBONACCI_GENERATOR_HPP_
#define __FIBONACCI_GENERATOR_HPP_

#include "congurent_generator.hpp"
#include <vector>
#include <algorithm>
#include <cstdint>

namespace randGen
{


class Fibonacci
{
private:
    Congurent initGen;
    std::vector<double> R_arr;
    double& R_;
    size_t a_;
    size_t b_;
public:
    explicit Fibonacci(double seed = cpow(2.,-52),
                       size_t a = 63, size_t b = 31);
    void srand(double seed, size_t a = 63, size_t b = 31);
    double rand();
};



}

#endif//__FIBONACCI_GENERATOR_HPP_
