#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color)
{
    auto r = pixel_color.getX();
    auto g = pixel_color.getY();
    auto b = pixel_color.getZ();

    //to prevent number from going under 0 or over 255 due to rounding errors
    auto clamp = [](double x){return x < 0.0 ? 0: (x > 1.0 ? 1: x);};

    int rbyte = int(255.0 * clamp(r));
    int gbyte = int(255.0 * clamp(g));
    int bbyte = int(b);

    out << rbyte << " " << gbyte << " " << bbyte << "\n";

}

#endif 