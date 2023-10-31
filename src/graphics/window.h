/*
    Window
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "text.h"
#include "button.h"
namespace Graphics{
    class Window{
        private:
        public:
            int x, y, width, height;
            std::string title;
            std::vector<Text*> texts;
            std::vector<Button*>  buttons;

            Window(std::string title, int x, int y, int width, int height);

            void AddText(Text* t);
            void AddButton(Button* b);
    };
} 
#include "window.cpp"
#endif