#ifndef __MERSENNE_TWISTER_HPP_
#define __MERSENNE_TWISTER_HPP_

#include <random>

#include "constexpr_pow.hpp"

namespace randGen
{



class Mersenne
{
private:
    std::mt19937 generator;
    std::uniform_real_distribution<double> distr;
public:
    explicit Mersenne(double seed = cpow(2.,-52))
        : generator(seed)
        , distr(0.,1.)
    {}
    double rand()
    {
        return distr(generator);
    }
};



}//namespace randGen

#endif//__MERSENNE_TWISTER_HPP_
