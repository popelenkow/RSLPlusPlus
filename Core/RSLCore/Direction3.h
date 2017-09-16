#ifndef DIRECTION3_H
#define DIRECTION3_H

#include "MathConstants.h"
#include "Vector3.h"
#include "Modulus.h"
#include "Period.h"

namespace rsl
{
template <typename T>
class Direction3 final
{
    //conditions
private:
    static_assert(std::is_floating_point<T>::value, "Template instantiation of Class are not floating point");

    //variables
private:
    T _a; //Azimuthal
    T _p; //Polar

    //get set variables
public:
    // [-180; 180)
    inline void setAzimuthal(T value)
    {
        _a = Period<T>::calculate(value, T(-180.0), T(180.0));
    }
    // [-180; 180)
    inline void setPolar(T value)
    {
        _p = Period<T>::calculate(value, T(-180.0), T(180.0));
    }
    // [-180; 180)
    inline T getAzimuthalFast() const
    {
        return _a;
    }
    // [-180; 180)
    inline T getPolarFast() const
    {
        return _p;
    }
    // [-180; 180)
    inline T getAzimuthal() const
    {
        T azimuthal, quotient;

        quotient = getOverflowPolar();
        bool isOverflow = (quotient != T(0.0));

        if (isOverflow)
        {
            azimuthal = T(180.0) - _a;
            azimuthal = putPeriod(azimuthal);
        }
        else
        {
            azimuthal = _a;
        }
        return azimuthal;
    }
    // [-90; 90]
    inline T getPolar() const
    {
        T polar, azimuthal, quotient;

        quotient = getOverflowPolar();
        bool isOverflow = (quotient != T(0.0));

        if (isOverflow)
        {
            polar = quotient * T(180.0) - _p;
        }
        else
        {
            polar = _p;
        }
        return polar;
    }
private:
    // {-1, 0, 1}
    inline T getOverflowPolar() const
    {
        T quotient;
        quotient = _p / T(180.0);
        if (quotient != T(0.5))
        {
            quotient = std::round(quotient);
        }
        else
        {
            quotient = T(0.0);
        }
        return quotient;
    }

    //constructors
public:
    explicit Direction3(T azimuthal = T(), T polar = T())
    {
        setAzimuthal(azimuthal);
        setPolar(polar);
    }
    template <typename G>
    explicit Direction3(Direction3<G> value)
    {
        setAzimuthal(T(value.getAzimuthalFast()));
        setPolar(T(value.getPolarFast()));
    }
    explicit Direction3(Vector3<T> value)
    {
        T azimuthal = calculateAzimuthal(value);
        T polar = calculatePolar(value);

        setAzimuthal(azimuthal);
        setPolar(polar);
    }

    //methods
public:
    inline Vector3<T> createVector3() const
    {
        Vector3<T> res;
        T p = _p * DEG_TO_RAD;
        T a = _a * DEG_TO_RAD;
        res.X = std::cos(p) * std::cos(a);
        res.Y = std::cos(p) * std::sin(a);
        res.Z = std::sin(p);
        return res;
    }

    //static methods
public:
    static T calculateAzimuthal(Vector3<T> value)
    {
        //conditions
        static_assert(std::is_floating_point<T>::value, "Template method of Class are not floating point");

        T res = T(0.0);

        bool isNullX = (value.X == T(0.0));
        bool isNullY = (value.Y == T(0.0));

        if (!isNullX || !isNullY)
        {
            T magnitude = value.magnitude();
            T x = value.X / magnitude;
            res = std::acos(x) * RAD_TO_DEG;
            res *= Modulus<T>::sign(value.Y);
        }

        return res;
    }
    static T calculatePolar(Vector3<T> value)
    {
        //conditions
        static_assert(std::is_floating_point<T>::value, "Template method of Class are not floating point");

        T res = T(0.0);

        bool isNullZ = (value.Z == T(0.0));

        if (!isNullZ)
        {
            T magnitude = value.magnitude();
            T x = value.Z / magnitude;
            res = std::acos(x) * RAD_TO_DEG;
            res *= Modulus<T>::sign(value.Z);
        }

        return res;
    }

    //operators
public:
    inline Direction3<T> operator+(Direction3<T> value) const
    {
        Direction3<T> res;
        T a = getAzimuthal() + value.getAzimuthal();
        T p = getPolar() + value.getPolar();
        res.setAzimuthal(a);
        res.setPolar(p);
        return res;
    }
    inline Direction3<T> operator-(Direction3<T> value) const
    {
        Direction3<T> res;
        T a = getAzimuthal() - value.getAzimuthal();
        T p = getPolar() - value.getPolar();
        res.setAzimuthal(a);
        res.setPolar(p);
        return res;
    }
    inline Vector3<T> operator*(T value) const
    {
        Vector3<T> res;
        res = createVector3();
        res *= value;
        return res;
    }
    inline Vector3<T> operator/(T value) const
    {
        Vector3<T> res;
        res = createVector3();
        res /= value;
        return res;
    }
    inline Vector3<T> operator*(Vector3<T> value) const
    {
        Vector3<T> res;
        Direction3<T> direction;
        direction = (*this) + Direction3<T>(value);
        res = direction * value.magnitude();
        return res;
    }
    inline Direction3<T> operator+=(Direction3<T> value)
    {
        T a = getAzimuthal() + value.getAzimuthal();
        T p = getPolar() + value.getPolar();
        setAzimuthal(a);
        setPolar(p);
        return *this;

    }
    inline Direction3<T> operator-=(Direction3<T> value)
    {
        T a = getAzimuthal() - value.getAzimuthal();
        T p = getPolar() - value.getPolar();
        setAzimuthal(a);
        setPolar(p);
        return *this;
    }
    inline bool operator==(Direction3<T> value) const
    {
        bool b = true;
        b =  b && (getAzimuthal() == value.getAzimuthal());
        b =  b && (getPolar() == value.getPolar());
        return b;
    }
    inline bool operator!=(Direction3<T> value) const
    {
        return !((*this) == value);
    }
};
}

#endif // DIRECTION3_H
