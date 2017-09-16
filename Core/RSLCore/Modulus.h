#ifndef MODULUS_H
#define MODULUS_H

#include <type_traits>

namespace rsl
{
template <typename T>
class Modulus final
{
    //conditions
private:
    static_assert(std::is_arithmetic<T>::value, "Template instantiation of Class are not arithmetic");

    //static methods
public:
    static inline T sign(T value)
    {
        T res;
        if (isPositive(value))
        {
            res = T(1);
        }
        else
        {
            res = T(-1);
        }
        return res;
    }
    static inline T absolute(T value)
    {
        return value * Sign(value);
    }
    static inline bool isPositive(T value)
    {
        return value >= T(0);
    }
    static inline bool isNegative(T value)
    {
        return value < T(0);
    }
};
}

#endif // MODULUS_H
