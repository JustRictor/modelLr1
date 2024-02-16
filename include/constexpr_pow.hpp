#ifndef __CONSTEXPR_POW_HPP_
#define __CONSTEXPR_POW_HPP_

template<typename T>
constexpr T cpow(T num, int pow)
{
    if(pow < 0)
        return cpow(1/num,-pow);
    if(pow == 0)
        return 1;
    return num * cpow(num,pow-1);
}

#endif//__CONSTEXPR_POW_HPP_
