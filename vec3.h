#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

struct vec3
{
    double e[3];

    vec3(): e{0,0,0}{}

    vec3(double x, double y, double z) : e{x,y,z}{}

    //get functions
    double getX() const { return e[0]; }
    double getY() const { return e[1]; }
    double getZ() const { return e[2]; }

    //operator overloading for vector calculations
    vec3 operator-() const {return vec3( -e[0], -e[1], -e[2]); } //unary -

    //subscript operation
    double operator[](int i) const {return e[i];} //for read only
    double& operator[](int i){return e[i];} //for modification

    //vector addition
    vec3& operator+=(const vec3& v)
    { 
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];

        return *this; 
    }

    //scalar multiplication
    vec3& operator*=(double t)
    { 
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this; 
    }

    //scalar division
    vec3& operator/=(double t)
    { 
        return *this *= 1/t; 
    }

    //eucledian length
    double length_squared() const
    {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    //length
    double length() const
    {
        return std::sqrt(length_squared());
    }

};

using point3 = vec3;

//inline skips function call and directly copies the function within
//display elements of a vector
inline std::ostream& operator<<(std::ostream& out, const vec3& v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//vector addition
inline vec3 operator+(const vec3& u, const vec3& v )
{
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//vector subtraction
inline vec3 operator-(const vec3& u, const vec3& v )
{
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}


//vector component wise multiplication
inline vec3 operator*(const vec3& u, const vec3& v )
{
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//vector scalar multiplication(scalar on left)
inline vec3 operator*(double t, const vec3& v)
{
    return vec3(t* v.e[0], t* v.e[1], t* v.e[2]);
}

//vector scalar multiplication(scalar on right)
inline vec3 operator*(const vec3& v, double t)
{
    return t * v; //using previous overload
}

//vector scalar division
inline vec3 operator/(const vec3& v, double t)
{
    return (1/t) * v; //using previous overload
}

//dot product
inline double dot(const vec3& u, const vec3& v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2]; 
}

//cross-product
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(
        u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]
    );
}

//unit-vector
inline vec3 unit_vector(const vec3& v)
{
    return v / v.length();
}


#endif