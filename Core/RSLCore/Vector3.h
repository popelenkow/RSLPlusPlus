#ifndef VECTOR3_H
#define VECTOR3_H


#include <cmath>
#include <type_traits>

namespace rsl
{
template <typename T>
class Vector3 final
{
    //conditions
private:
    static_assert(std::is_arithmetic<T>::value, "Template instantiation of Class are not arithmetic");

    //variables
public:
    T X;
    T Y;
    T Z;

    //constructors
public:
    constexpr explicit Vector3(T x = T(), T y = T(), T z = T()) : X(x), Y(y), Z(z)
    {
    }
    template <typename G>
    constexpr explicit Vector3(Vector3<G> value) : X(T(value.X)), Y(T(value.Y)), Z(T(value.Z))
    {
    }

    //methods
public:
    inline T magnitude() const
    {
        T value;
        value = X*X+Y*Y+Z*Z;
        value = std::sqrt(value);
        return value;
    }
    inline Vector3<T> normalized() const
    {
        //conditions
        static_assert(std::is_floating_point<T>::value, "Template instantiation of Class are not floating point");

        Vector3<T> value;
        T m = magnitude();
        value.X = X / m;
        value.Y = Y / m;
        value.Z = Z / m;
        return value;
    }

    //operators
public:
    inline T operator[](std::size_t id)
    {
        T t;
        if (id == 0)
        {
            t = X;
        }
        else if (id == 1)
        {
            t = Y;
        }
        else if (id == 2)
        {
            t = Z;
        }
        return t;
    }
    inline Vector3<T> operator+(Vector3<T> value) const
    {
        Vector3<T> v;
        v.X = X + value.X;
        v.Y = Y + value.Y;
        v.Z = Z + value.Z;
        return v;
    }
    inline Vector3<T> operator-(Vector3<T> value) const
    {
        Vector3<T> v;
        v.X = X - value.X;
        v.Y = Y - value.Y;
        v.Z = Z - value.Z;
        return v;
    }
    inline Vector3<T> operator*(T value) const
    {
        Vector3<T> v;
        v.X = X * value;
        v.Y = Y * value;
        v.Z = Z * value;
        return v;
    }
    inline Vector3<T> operator/(T value) const
    {
        Vector3<T> v;
        v.X = X / value;
        v.Y = Y / value;
        v.Z = Z / value;
        return v;
    }
    inline Vector3<T> operator+=(Vector3<T> value)
    {
        X += value.X;
        Y += value.Y;
        Z += value.Z;
        return *this;
    }
    inline Vector3<T> operator-=(Vector3<T> value)
    {
        X -= value.X;
        Y -= value.Y;
        Z -= value.Z;
        return *this;
    }
    inline Vector3<T> operator*=(T value)
    {
        X *= value;
        Y *= value;
        Z *= value;
        return *this;
    }
    inline Vector3<T> operator/=(T value)
    {
        X /= value;
        Y /= value;
        Z /= value;
        return *this;
    }
    inline bool operator==(Vector3<T> value) const
    {
        bool b = true;
        b =  b && (X == value.X);
        b =  b && (Y == value.Y);
        b =  b && (Z == value.Z);
        return b;
    }
    inline bool operator!=(Vector3<T> value) const
    {
        return !((*this) == value);
    }
};
}


#endif // VECTOR3_H
