/*
    Window
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>

namespace Graphics{
    class Window{
        private:
            int x, y, width, height;
            std::string title;
        public:
            Window(std::string title, int x, int y, int width, int height);
    };
} 
#include "window.cpp"
#endif