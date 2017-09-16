#ifndef PERIOD_H
#define PERIOD_H

#include <cmath>
#include <type_traits>

namespace rsl
{
template <typename T>
class Period
{
    //conditions
private:
    static_assert(std::is_arithmetic<T>::value, "Template instantiation of Class are not arithmetic");

    //static methods
public:
    static inline  T calculate(T value, T left, T right)
    {
        //conditions
        static_assert(std::is_arithmetic<T>::value, "Template instantiation of Class are not arithmetic");

        T res;
        double quotient;
        quotient = double(value - left) / double(right-left);
        quotient = std::floor(quotient);
        res = value - T(quotient)*(right-left);
        return res;
    }
};
}

#endif // PERIOD_H
