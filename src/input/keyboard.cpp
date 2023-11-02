/*
*/
#include "keyboard.h"


Input::Keyboard::Keyboard(){
    tcgetattr(STDIN_FILENO, &oldt);
    // copy old settings
    newt = oldt;

    //newt.c_lflag &= ~(ICANON);
    newt.c_lflag &= ~(ICANON | ECHO); 

    // apply it
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    
    //int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    //fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);


    //timeout(0);


}

char Input::Keyboard::getKey(){
    char c;
    read(STDIN_FILENO, &c, 1);
    return c;  
}

Input::Keyboard::~Keyboard(){
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}