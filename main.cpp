#include <iostream>
#include <fstream>

int main() {

    /*
    std::ofstream imageFile("output.ppm"); creates an output file stream to open and write to a file called output.ppm.
    imageFile << "P3\n" writes the PPM file's header, specifying that the file will use the P3 format (plain text format).
    imageFile << width << " " << height << "\n" writes the dimensions of the image (in this case, 800x600). This tells any software reading the file how large the image is.
    imageFile << "255\n" writes the maximum color value for each color channel (Red, Green, Blue), indicating that each channel will have values from 0 to 255.
    */

    // Image dimensions
    const int width = 800;
    const int height = 600;

    // Open a .ppm file for writing
    std::ofstream imageFile("output.ppm");
    imageFile << "P3\n" << width << " " << height << "\n255\n";

    // Write pixel data (simple gradient)
    for (int y = height; y > 0; --y) {

        std::clog << "\rScanlines Remaining: " << y - 1 << std::flush;

        for (int x = 0; x < width; ++x) {
            int r = static_cast<int>(255.0 * x / (width - 1));
            int g = static_cast<int>(255.0 * y / (height - 1));
            int b = 128;  // constant value for blue
            imageFile << r << " " << g << " " << b << "\n";
        }
    }

    std::clog << "\rDone.                    \n";

    imageFile.close();
    std::cout << "Image written to output.ppm\n";
    return 0;
}
