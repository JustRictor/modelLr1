#include <iostream>
#include "congurent_generator.hpp"
#include "fibonacci_generator.hpp"
#include "mersenne_twister.hpp"
#include "metrics.hpp"

int main()
{
    std::vector<double> a{1, 2, 3};
    std::cout << metrics::expectation(a) << "\n"
              << metrics::varience(a)    << "\n"
              << metrics::deviation(a) << std::endl;
    return 0;
}
