/*
*/
#include "keyboard.h"



Input::Keyboard::Keyboard(){
    tcgetattr(STDIN_FILENO, &oldt);
    // copy old settings
    newt = oldt;

    newt.c_lflag &= ~(ICANON);
    newt.c_lflag &= ~(ICANON | ECHO); 

    // apply it
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    timeout(0);
}

char Input::Keyboard::getKey(){
    int ch = getch();
    refresh();
    return ch;  
}

Input::Keyboard::~Keyboard(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}