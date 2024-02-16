#ifndef __GENERATOR_INTERFACE_HPP_
#define __GENERATOR_INTERFACE_HPP_

namespace randGen
{

enum class GeneratorType
{
    Congurent, Fibonacci, Mersenne,
};

class Generator
{
public:
    virtual double rand() = 0;
    virtual GeneratorType getType() = 0;
};



}//namespace randGen

#endif//__GENERATOR_INTERFACE_HPP_
