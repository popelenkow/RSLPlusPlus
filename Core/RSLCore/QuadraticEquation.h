#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include <vector>
#include <cmath>
#include <type_traits>
#include "Complex.h"

namespace rsl
{
template <typename T>
class QuadraticEquation final
{
    //conditions
private:
    static_assert(std::is_floating_point<T>::value, "Template instantiation of Class are not floating point");

    //static methods
public:
    static std::vector<T> Calculate(T a, T b, T c)
    {
        T d = Discriminant(a, b, c);
        std::vector<T> res;

        if (d == T(0.0))
        {
            T bb = -b / T(2.0);
            res.push_back(bb);
        }
        else if (d > T(0.0))
        {
            T dd = std::sqrt(d);
            T bb = -b / T(2.0);
            res.push_back(bb - dd);
            res.push_back(bb + dd);
        }

        return res;
    }
private:
    static inline T Discriminant(T a, T b, T c)
    {
        return b * b / T(4.0) - a * c;
    }
};

/*
template <typename T>
class QuadraticEquation<Complex<T>>
{
public:
    static std::vector<Complex<T>> Calculate(Complex<T> a, Complex<T> b, Complex<T> c)
    {
       //....
    }
private:
    static inline Complex<T> Discriminant(Complex<T> a, Complex<T> b, Complex<T> c)
    {
        //....
    }
};
*/
}

#endif // QUADRATICEQUATION_H
