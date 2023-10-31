#include "screen.h"

//

Graphics::Screen::Screen(std::string title){
    updateDim();

    // Copy title
    this->title = title;

    // Clear screen
    system("clear");


}   

void Graphics::Screen::AddWindow(Window* window){
    this->windows.push_back(window);
}

void Graphics::Screen::Refresh(){
    if(updateDim() != 1){
        // Clear screen
        system("clear");
        Display();
    }
    
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

        for(auto& t : windows[i]->texts){
            printAt(t->x + windows[i]->x, t->y + windows[i]->y, t->text.c_str(), TEXT_BG);
        }

        for(auto& b : windows[i]->buttons){
            int w = b->width;
            if(b->text.length() > w) w = b->text.length();
            for(int y = b->y; y < b->height; y++){
                for(int x = b->x; x < w; x++){
                    printAt(x + windows[i]->x, y + windows[i]->y, " ", BUTTON_BG);
                }
            }
            printAt(b->x + windows[i]->x, b->y + windows[i]->y, b->text.c_str(), TEXT_BG);
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

void Graphics::Screen::printAt(int x, int y, const char* text, enum RenderColor c){
    printf("\033[%d;%dH",y , x);
    int r = 0, g = 0, b = 0;
    switch(c){
        case DEFAULT_GRAY:
            r = 100;
            b = 100;
            g = 100;
            break;

        case TEXT_BG:
            r = 130;
            b = 120;
            g = 120;
            break;

        case BUTTON_BG:
            r = 80;
            b = 80;
            g = 80;
    }
    printf("\033[48;2;%d;%d;%dm %s  \033[48;2;0;0;0m", r, g, b, text);
    fflush(stdout);
}



int Graphics::Screen::updateDim(){
     // Get window size
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    int oldW = width, oldY = height;

    this->width = size.ws_col;
    this->height = size.ws_row;

    return oldW == width && height == oldY;
}