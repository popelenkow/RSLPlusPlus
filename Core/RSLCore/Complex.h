#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <type_traits>

namespace rsl
{
template <typename T>
class Complex final
{
    //conditions
private:
    static_assert(std::is_arithmetic<T>::value, "Template instantiation of Class are not arithmetic");

    //variables
public:
    T R; //Real
    T I; //Imaginary

    //constructors
public:
    constexpr explicit Complex(T real = T(), T imaginary = T()) : R(real), I(imaginary)
    {
    }
    template <typename G>
    constexpr explicit Complex(Complex<G> value) : R(value.R), I(value.I)
    {
    }

    //methods
public:
    Complex<T> conjugate() const
    {
        Complex<T> res(R, -I);
        return res;
    }

    //operators
public:
    inline Complex<T> operator+(Complex<T> value) const
    {
        Complex<T> res;
        res.R = R + value.R;
        res.I = I + value.I;
        return res;
    }
    inline Complex<T> operator-(Complex<T> value) const
    {
        Complex<T> res;
        res.R = R - value.R;
        res.I = I - value.I;
        return res;
    }
    inline Complex<T> operator*(Complex<T> value) const
    {
        Complex<T> res;
        res.R = (this->R)*value.R - (this->I)*value.I;
        res.I = (this->I)*value.R + (this->R)*value.I;
        return res;
    }
    inline Complex<T> operator/(Complex<T> value) const
    {
        Complex<T> a = (*this);
        Complex<T> b = value;
        Complex<T> _b = b.conjugate();
        b *= _b;
        a *= _b;
        Complex<T> res = a/b.R;
        return res;

    }
    inline Complex<T> operator*(T value) const
    {
        Complex<T> res;
        res.R = R * value;
        res.I = I * value;
        return res;
    }
    inline Complex<T> operator/(T value) const
    {
        Complex<T> res;
        res.R = R / value;
        res.I = I / value;
        return res;
    }
    inline Complex<T> operator+=(Complex<T> value)
    {
        R += value.R;
        I += value.I;
        return *this;
    }
    inline Complex<T> operator-=(Complex<T> value)
    {
        R -= value.R;
        I -= value.I;
        return *this;
    }
    inline Complex<T> operator*=(Complex<T> value)
    {
        Complex<T> res = (*this)*value;
        R = res.R;
        I = res.I;
        return *this;
    }
    inline Complex<T> operator/=(Complex<T> value)
    {
        Complex<T> res = (*this)/value;
        R = res.R;
        I = res.I;
        return *this;
    }
    inline Complex<T> operator*=(T value)
    {
        R *= value;
        I *= value;
        return *this;
    }
    inline Complex<T> operator/=(T value)
    {
        R /= value;
        I /= value;
        return *this;
    }
    inline bool operator==(Complex<T> value) const
    {
        bool b = true;
        b =  b && (R == value.R);
        b =  b && (I == value.I);
        return b;
    }
    inline bool operator!=(Complex<T> value) const
    {
        return !((*this) == value);
    }
};
}

#endif // COMPLEX_H
