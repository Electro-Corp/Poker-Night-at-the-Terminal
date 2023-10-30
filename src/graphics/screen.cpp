#include "screen.h"

//

Graphics::Screen::Screen(std::string title){
    // Get window size
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    this->width = size.ws_col;
    this->height = size.ws_row;

    // Copy title
    this->title = title;

    // Clear screen
    system("clear");


}   

void Graphics::Screen::AddWindow(Window* window){
    this->windows.push_back(window);
}

void Graphics::Screen::Display(){
    // Render Screen titlebar
    printAt((width / 2) - (title.length() / 2) - 1, 0, title.c_str());

    for(int i = 0; i < windows.size(); i++){
        // Render windows   
        for(int y = windows[i]->y; y < windows[i]->height; y++){
            for(int x = windows[i]->x; x < windows[i]->width; x++){
                printAt(x, y, " ");
            }
        }
    }
}



/*
    Internal funcs
*/
void printChar(int x, int y, char c){
    printf("\033[%d;%dH",y , x);
    printf("\033[48;2;%d;%d;%dm %c  \033[48;2;0;0;0m", 100, 100, 100, c);
}

void Graphics::Screen::printAt(int x, int y, const char* text){
    printf("\033[%d;%dH",y , x);
    printf("\033[48;2;%d;%d;%dm %s  \033[48;2;0;0;0m", 100, 100, 100, text);
    fflush(stdout);
}

