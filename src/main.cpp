#include <iostream>
#include "graphics/screen.h"

int main(){
    // Create screen
    Graphics::Screen screen("Poker Night at the Terminal");

    // Create basic window
    Graphics::Window choicesWindow("Choices:", 10, 10, 80, 20);
    Graphics::Text choiceText("Choices:", 2, 2);

    choicesWindow.AddText(&choiceText);

    // Add it
    screen.AddWindow(&choicesWindow);


    screen.Display();
    while(1){
        screen.Refresh();
    }
    
    return 0;
}