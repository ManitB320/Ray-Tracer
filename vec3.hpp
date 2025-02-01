#ifndef VEC3_HPP
#define VEC3_HPP


struct vec3
{
    double x, y, z;

    vec3(double x_ = 0, double y_ = 0, double z_ = 0) : x(x_), y(y_), z(z_){}

    //get functions
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    //operator overloading for vector calculations
    vec3 operator+(const vec3& v){return vec3(x + v.x, y + v.y, z + v.z); }
    vec3 operator-(const vec3& v){return vec3(x - v.x, y - v.y, z - v.z); }
    vec3 operator*(double scalar){return vec3(scalar*x, scalar*y, scalar*z); }

};


#endif