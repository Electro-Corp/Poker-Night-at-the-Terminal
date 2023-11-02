/*
*/
#include "button.h"

Graphics::Button::Button(std::string text, int x, int y, int width, int height, void (*onClick)()){
    this->text = text;
    this->onClick = onClick;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}


void Graphics::Button::updateSelect(){
    this->isSelected = !this->isSelected;
}