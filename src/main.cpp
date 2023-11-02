#include <iostream>
#include <thread>
#include "graphics/screen.h"
#include "input/inputmanager.h"

void updateInput(Graphics::Screen screen, Graphics::Window choicesWindow, Input::InputManager* inputMan){
    if(choicesWindow.InputButtons(inputMan->InputTick())) screen.Display();
}

int main(){
    // Create inputMan
    Input::InputManager* inputMan = new Input::InputManager();

    // Create screen
    Graphics::Screen screen("Poker Night at the Terminal");


    // Create choice window
    Graphics::Window choicesWindow("Choices:", 10, 10, 40, 10);
    Graphics::Text choiceText("Choices:", 2, 2);
    Graphics::Button fold("FOLD", 5, 5, 6, 2);
    Graphics::Button call("CALL", 17, 5, 6, 2);
    Graphics::Button raise("RAISE", 27, 5, 6, 2);

    // Create table
    Graphics::Window tableWindow("View", 60, 5, 110, 30);
    Graphics::Image tableImage("assets/images/damn30.ppm", 0, 0);
    tableWindow.AddImage(&tableImage);
    

    choicesWindow.AddText(&choiceText);
    choicesWindow.AddButton(&fold); 
    choicesWindow.AddButton(&call); 
    choicesWindow.AddButton(&raise); 

    // Add it
    screen.AddWindow(&choicesWindow);
    screen.AddWindow(&tableWindow);


    screen.Display();


    while(1){
        std::thread goof(updateInput, screen, choicesWindow, inputMan);
        screen.Refresh();
        usleep(1000);
        goof.join();
    }
    
    return 0;
}