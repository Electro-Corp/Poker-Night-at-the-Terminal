/*
*/
#include "window.h"

Graphics::Window::Window(std::string title, int x, int y, int width, int height){
    this->title;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Graphics::Window::AddText(Text* t){
    this->texts.push_back(t);
}

void Graphics::Window::AddButton(Button* b){
    this->buttons.push_back(b);
}