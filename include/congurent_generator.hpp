#ifndef __CONGURENT_GENERATOR_HPP_
#define __CONGURENT_GENERATOR_HPP_

#include "generator_interface.hpp"

#include <cmath>
#include <cstdint>

namespace randGen
{



class Congurent : public Generator
{
private:
    const uint16_t A_;
    const uint16_t C_;
    static const uint32_t M_ = -1;
    double R_;
public:
    explicit Congurent(double seed = std::pow(2.,-52),
                       uint16_t A = std::pow(7,5), uint16_t C = 0);
    double rand() override;
    GeneratorType getType() override;

};



}//namespace randGen

#endif//__CONGURENT_GENERATOR_HPP_
