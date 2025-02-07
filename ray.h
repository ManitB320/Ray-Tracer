#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
private:
    point3 orig;
    vec3 dir;
public:

    ray(){}

    ray(const vec3& direction, const point3& origin, double t): dir(direction), orig(origin){}

    const point3& origin(){return orig;}
    const vec3& direction(){return dir;}

    point3 at(double t) const 
    {
        return orig + t * dir;
    }
    
};

#endif