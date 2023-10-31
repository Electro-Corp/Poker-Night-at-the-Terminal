/*
    Window
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "text.h"
namespace Graphics{
    class Window{
        private:
        public:
            int x, y, width, height;
            std::string title;
            std::vector<Text*> texts;

            Window(std::string title, int x, int y, int width, int height);

            void AddText(Text* t);
    };
} 
#include "window.cpp"
#endif