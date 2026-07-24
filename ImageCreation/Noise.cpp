#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

/*

This is a PPM header:

    P3
    50 50
    255

    It describes basic info about the image and its type:

        a 50x50 pixel image in PPM format, where each pixel's color is defined by three values (R, G, B) ranging from 0 to 255.
        In this case, the pixel values are set to create a gradient effect.
        255 represents the maximum value (8-bit scale from 0 to 255) typically used for color channels (RGB).
        
        - P3: The "magic number" identifier for plain/ASCII Portable Pixmap files.
            the P3 format specifies a sequence of RGB triplets (Red, Green, Blue integers)
        - 50 50: The dimensions of the raster grid, indicating an image width of 50 pixels and a height of 50 pixels.
        - 255: The maximum color component value for each RGB channel, meaning color values range from
            0 to 255 (standard 8-bit color depth)

How to compile this code:

    "g++ -std=c++23 Gradient.cpp -o Gradient" (compile)
        then
    "./Gradient.exe" (run)
        then
    "we get imageGradient.ppm file in the same directory"

    or

    "g++ Gradient.cpp (compile)
        then
    "./a.exe" (run)
        then
    "we get imageGradient.ppm file in the same directory"

*/

int main() {

    std::ofstream image; // This creates an output file-stream object named image. ofstream = output file stream, image = the variable name. You use image to write data into a file. It is similar to how std::cout writes text to the terminal: std::cout << "Hello";
    image.open("Noise.ppm"); // This opens or creates a file named: "Noise.ppm" You can also create and open the file in one line: std::ofstream image("Noise.ppm");

    srand(time(0)); // Seed the random number generator with the current time to ensure different random values on each run.

    if (image.is_open()) { // This checks whether the file was opened/created successfully.
        
        image << "P3" << std::endl; // The << operator sends data into the file. This writes: "P3". P3 identifies the file as an ASCII PPM image.
        image << "250 250" << std::endl; // This writes the image dimensions: "250 250". The first number is the width and the second is the height: width = 250 pixels, height = 250 pixels
        image << "255" << std::endl; // This writes the maximum color value. In this PPM file, each red, green, and blue component can have a value from: 0 to 255. For example: 255 0 0

        for (int y = 0; y < 250; y++) {
            for (int x = 0; x < 250; x++) {
                image << rand() % 255 << " " << rand() % 255 << " " << rand() % 255 << std::endl;
            }
        }
    }

    image.close(); // This closes the file. Closing the file: finishes writing remaining data, releases the file resource, prevents further writing through that stream
}