/*
*/
#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
namespace Graphics{
    class Button{
        private:
        public:
            std::string text;
            int x, y, width, height;
            bool isSelected = false;
            void (*onClick)();
            Button(std::string text, int x, int y, int width, int height, void (*onClick)());

            void updateSelect();
    };
}
#include "button.cpp"
#endif