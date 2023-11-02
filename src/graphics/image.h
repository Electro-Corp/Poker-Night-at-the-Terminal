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
            std::vector<Color> colorData;

            std::string imagePath;
            int x, y, width, height;
            Image(std::string, int , int);

    };
}
#include "image.cpp"
#endif