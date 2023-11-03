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
#include <time.h>

#include "window.h"


namespace Graphics{

    enum RenderColor{
        DEFAULT_GRAY = 0,
        TEXT_BG = 1,
        BUTTON_BG_NORMAL = 2,
        BUTTON_BG_SELECTED = 3,
        CURRENT_WIN = 4
    };

    class Screen{
        private:
            int width, height;
            int currentContext = 0;
            // Container for all windows
            std::vector<Window*> windows;
            // Title
            std::string title;

            time_t seconds;



            // Display funcs
            void printAt(int x, int y, const char* text, enum RenderColor c = DEFAULT_GRAY);
            
            // Intenral
            int updateDim();
            void closeMostRecent();
        public:
            Screen(std::string title);

            void AddWindow(Window* window);

            void CreateTimedWindow(std::string person, std::string text, std::string path, int time);

            void Display();
            void Refresh();

            bool HandleInput(char c);

            void DialogBox(std::string title, std::string message);


            
    };
}

#include "screen.cpp"
#endif