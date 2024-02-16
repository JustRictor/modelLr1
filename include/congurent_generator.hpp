#ifndef __CONGURENT_GENERATOR_HPP_
#define __CONGURENT_GENERATOR_HPP_

#include <cmath>
#include <cstdint>

namespace randGen
{



class Congurent
{
private:
    const uint16_t A_;
    const uint16_t C_;
    static const uint32_t M_ = -1;
    double R_;
public:
    explicit Congurent(double seed = std::pow(2.,-52),
                       uint16_t A = std::pow(7,5), uint16_t C = 0);
    void srand(double seed);
    double rand();


};



}//namespace randGen

#endif//__CONGURENT_GENERATOR_HPP_
