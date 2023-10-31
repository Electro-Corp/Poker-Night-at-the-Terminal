/*
*/
#include "button.h"

Graphics::Button::Button(std::string text, int x, int y, int width, int height){
    this->text = text;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}