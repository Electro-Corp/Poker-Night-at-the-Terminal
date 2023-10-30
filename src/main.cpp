#include <iostream>
#include "graphics/screen.h"

int main(){
    // Create screen
    Graphics::Screen screen("Poker Night at the Terminal");

    // Create basic window
    Graphics::Window choicesWindow("Choices:", 10, 10, 80, 20);

    // Add it
    screen.AddWindow(&choicesWindow);

    while(1){
        screen.Display();
    }
    
    return 0;
}