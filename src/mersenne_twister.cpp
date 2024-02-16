#include "mersenne_twister.hpp"

randGen::Mersenne::Mersenne(double seed)
    : generator(seed)
    , distr(0.,1.)
{}

double randGen::Mersenne::rand()
{
    return distr(generator);
}
