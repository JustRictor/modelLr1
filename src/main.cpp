#include <iostream>
#include "congurent_generator.hpp"
#include "fibonacci_generator.hpp"


int main()
{
    randGen::Fibonacci r;
    for(size_t i = 0; i < 1000; i++)
        std::cout << r.rand() << " " << std::endl;
    return 0;
}
