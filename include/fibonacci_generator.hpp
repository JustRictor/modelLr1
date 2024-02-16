#ifndef __FIBONACCI_GENERATOR_HPP_
#define __FIBONACCI_GENERATOR_HPP_

#include "generator_interface.hpp"
#include "congurent_generator.hpp"

#include <vector>
#include <algorithm>
#include <cstdint>


namespace randGen
{


class Fibonacci : public Generator
{
private:
    Congurent initGen;
    std::vector<double> R_arr;
    double& R_;
    const size_t a_;
    const size_t b_;
public:
    explicit Fibonacci(double seed = std::pow(2.,-52),
                       size_t a = 63, size_t b = 31);
    double rand() override;
    GeneratorType getType() override;
};



}//namespace randGen

#endif//__FIBONACCI_GENERATOR_HPP_
