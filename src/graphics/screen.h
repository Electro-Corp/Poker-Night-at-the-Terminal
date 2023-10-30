/*
    Screen
*/
#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>
#include <cstring>

#include "window.h"


namespace Graphics{
    class Screen{
        private:
            int width, height;
            // Container for all windows
            std::vector<Window*> windows;
            // Title
            std::string title;


            // Display funcs
            void printAt(int x, int y, const char* text);
        public:
            Screen(std::string title);

            void AddWindow(Window* window);

            void Display();

            
    };
}

#include "screen.cpp"
#endif