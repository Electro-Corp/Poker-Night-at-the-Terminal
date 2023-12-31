/*
    Window
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "text.h"
#include "button.h"
#include "image.h"
namespace Graphics{
    class Window{
        private:
        public:
            // Position and size data
            int x, y, width, height;
            int index;
            bool exist = true, isTimed = false;
            int time, elap, start;
            // Title of window
            std::string title;
            // vecotrs
            std::vector<Text*> texts;
            std::vector<Button*>  buttons;
            std::vector<Image*> images;
            int currentButton = 0;

            Window(std::string title, int x, int y, int width, int height);
            Window(std::string person, std::string caption, int x, int y, int width, int height, int seconds);

            void AddText(Text* t);
            void AddButton(Button* b);
            void AddImage(Image* i);

            bool InputButtons(char c);
            
            void UpdateSelection(int);

            void CloseWindow();


    };
} 
#include "window.cpp"
#endif