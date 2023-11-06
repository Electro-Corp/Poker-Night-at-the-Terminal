/*
*/
#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>
namespace Graphics{

    typedef struct {
    int r, g, b;
    } Color;

    class Image{
        private:
        
        public:
            // Raw RGB data
            std::vector<Color> colorData;

            // Image path
            std::string imagePath;
            // Position and Size data
            int x, y, width, height;
            // Construrtert (speelinge)
            Image(std::string, int , int);

    };
}
#include "image.cpp"
#endif