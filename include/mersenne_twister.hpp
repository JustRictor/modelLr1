#ifndef __MERSENNE_TWISTER_HPP_
#define __MERSENNE_TWISTER_HPP_

#include "generator_interface.hpp"

#include <random>
#include <cmath>

namespace randGen
{



class Mersenne : public Generator
{
private:
    std::mt19937 generator;
    std::uniform_real_distribution<double> distr;
public:
    explicit Mersenne(double seed = std::pow(2.,-52));
    double rand() override;
    GeneratorType getType() override;
};



}//namespace randGen

#endif//__MERSENNE_TWISTER_HPP_
