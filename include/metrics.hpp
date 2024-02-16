#ifndef __METRICS_HPP_
#define __METRICS_HPP_

#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

namespace metrics
{



double expectation(std::vector<double> const& arr);

double varience(std::vector<double> const& arr);

double deviation(std::vector<double> const& arr);



}//namespace mestics

#endif//__METRICS_HPP_
