#include "screen.h"

//

Graphics::Screen::Screen(std::string title){
    // Get window size
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    this->width = size.ws_col;
    this->height = size.ws_row;

    //
}   

void Graphics::Screen::AddWindow(Window* window){
    this->windows.push_back(window);
}

void Graphics::Screen::Display(){
    
}