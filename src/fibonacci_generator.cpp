#include "fibonacci_generator.hpp"

randGen::Fibonacci::Fibonacci(double seed, size_t a, size_t b)
    : initGen(seed)
    , R_arr(std::max(a,b) + 1)
    , R_(R_arr[0])
    , a_(a)
    , b_(b)
{
    for(auto& R : R_arr)
        R = initGen.rand();
}

void randGen::Fibonacci::srand(double seed, size_t a, size_t b)
{
    a_ = a;
    b_ = b;
    R_arr.reserve(std::max(a_,b_) + 1);
    for(auto& R : R_arr)
        R = initGen.rand();
}

double randGen::Fibonacci::rand()
{
    for(size_t i = R_arr.size() - 1; i > 0; i--)
        R_arr[i] = R_arr[i-1];
    R_ = R_arr[a_] - R_arr[b_];
    if(R_arr[a_] < R_arr[b_])
        R_++;
    return R_;
}
