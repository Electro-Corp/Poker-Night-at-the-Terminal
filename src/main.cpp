#include <iostream>
#include <thread>
#include "graphics/screen.h"
#include "input/inputmanager.h"
int main(){
    // Create screen
    Graphics::Screen screen("Poker Night at the Terminal");

    // Create inputMan
    Input::InputManager* inputMan = new Input::InputManager();

    // Create basic window
    Graphics::Window choicesWindow("Choices:", 10, 10, 80, 20);
    Graphics::Text choiceText("Choices:", 2, 2);
    Graphics::Button bet("Bet", 5, 5, 10, 5);

    choicesWindow.AddText(&choiceText);
    choicesWindow.AddButton(&bet); 

    // Add it
    screen.AddWindow(&choicesWindow);


    screen.Display();


    while(1){
        inputMan->InputTick();
        screen.Refresh();
    }
    
    return 0;
}