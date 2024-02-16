#ifndef __CONGURENT_GENERATOR_HPP_
#define __CONGURENT_GENERATOR_HPP_

#include "constexpr_pow.hpp"
#include <cmath>
#include <cstdint>

namespace randGen
{



class Congurent
{
private:
    static constexpr uint16_t A_ = cpow(7,5);
    static constexpr uint16_t C_ = 0;
    static constexpr uint32_t M_ = -1;
    double R_;
public:
    explicit Congurent(double seed = cpow(2.,-52));
    void srand(double seed);
    double rand();


};



}//namespace randGen

#endif//__CONGURENT_GENERATOR_HPP_
