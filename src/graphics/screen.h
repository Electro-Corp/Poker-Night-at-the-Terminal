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

    enum RenderColor{
        DEFAULT_GRAY = 0,
        TEXT_BG = 1,
        BUTTON_BG = 2
    };

    class Screen{
        private:
            int width, height;
            // Container for all windows
            std::vector<Window*> windows;
            // Title
            std::string title;


            // Display funcs
            void printAt(int x, int y, const char* text, enum RenderColor c = DEFAULT_GRAY);
            
            // Intenral
            int updateDim();
        public:
            Screen(std::string title);

            void AddWindow(Window* window);

            void Display();
            void Refresh();


            
    };
}

#include "screen.cpp"
#endif