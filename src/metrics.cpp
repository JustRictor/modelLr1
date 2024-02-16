#include "metrics.hpp"

double metrics::expectation(const std::vector<double> &arr)
{
    return std::accumulate(arr.begin(),arr.end(),0) /
            static_cast<double>(arr.size());
}

double metrics::varience(const std::vector<double> &arr)
{
    const double M_ = expectation(arr);
    return std::accumulate(arr.begin(),arr.end(),0,
                           [M_](auto sum, auto x){
        return sum + (x - M_) * (x - M_);
    }) / static_cast<double>(arr.size());
}

double metrics::deviation(const std::vector<double> &arr)
{
    return std::sqrt(varience(arr));
}
