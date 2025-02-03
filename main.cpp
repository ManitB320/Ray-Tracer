#include <iostream>
#include <fstream>

#include "vec3.h"
#include "color.h"

int main() {

    /*
    std::ofstream imageFile("output.ppm"); creates an output file stream to open and write to a file called output.ppm.
    imageFile << "P3\n" writes the PPM file's header, specifying that the file will use the P3 format (plain text format).
    imageFile << width << " " << height << "\n" writes the dimensions of the image (in this case, 800x600). This tells any software reading the file how large the image is.
    imageFile << "255\n" writes the maximum color value for each color channel (Red, Green, Blue), indicating that each channel will have values from 0 to 255.
    */

    // Image dimensions
    constexpr int width = 800;
    constexpr int height = 600;

    // Open a .ppm file for writing
    std::ofstream imageFile("output.ppm");
    imageFile << "P3\n" << width << " " << height << "\n255\n";

    // To avoid calculating width -1 and height - 1 every loop
    const double inv_width = 1.0 / (width - 1);
    const double inv_height = 1.0 / (height - 1);


    // Write pixel data (simple gradient)
    for (int y = height - 1; y >= 0; --y) {

        std::clog << "\rScanlines Remaining: " << y << std::flush;

        for (int x = 0; x < width; ++x) {

            auto pixel_color = color(double(x) * inv_width, double(y) * inv_height, 128.0);

            write_color(imageFile, pixel_color);
        }
    }

    std::clog << "\rDone.                    \n";

    imageFile.close();
    std::cout << "Image written to output.ppm\n";
    return 0;
}
