/*
    Window
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>

namespace Graphics{
    class Window{
        private:
            std::string title;
        public:
            int x, y, width, height;

            Window(std::string title, int x, int y, int width, int height);
    };
} 
#include "window.cpp"
#endif