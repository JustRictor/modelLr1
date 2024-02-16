#include "metrics.hpp"

double metrics::expectation(const std::vector<double> &arr)
{
    double val = 0;
    std::for_each(arr.begin(),arr.end(),
                  [&val](auto n){
                      val+=n;
                  });
    return val / static_cast<double>(arr.size());
}

double metrics::varience(const std::vector<double> &arr)
{
    const double M_ = expectation(arr);
    double val = 0;
    std::for_each(arr.begin(),arr.end(),
                  [&val,M_](auto x){
                       val += (x - M_) * (x - M_);
                  });
    return val / static_cast<double>(arr.size());
}

double metrics::deviation(const std::vector<double> &arr)
{
    double val = std::sqrt(varience(arr));
    return val;
}
