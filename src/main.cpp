#include <iostream>
#include <thread>
#include "graphics/screen.h"
#include "input/inputmanager.h"
#include "poker/player.h"

Graphics::Screen *screen;
Poker::Player *Tycho;
Poker::Player *Heavy;

// Players
std::vector<Poker::Player> players;

void updateInput(Graphics::Window choicesWindow, Input::InputManager* inputMan){
    while(1)
        if(choicesWindow.InputButtons(inputMan->InputTick())) screen->Display();
}

void T_Update(){
    while(1){
        // What Tycho feels like doing/saying (mostly saying) this turn
        Poker::PLAYER_TICK_ACTION TychoAction = Tycho->Tick();
        if(TychoAction.isTalking){
            // He wants to say something (lamo)
            screen->CreateTimedWindow(
                Tycho->name,
                TychoAction.caption,
                "assets/images/TYCHO/TYCHO_DICE_C.ppm",
                TychoAction.seconds
            );
        }
    }
}



void D_call(){
    //screen->DialogBox("CALL", "CALL?");
    Poker::PLAYER_TICK_ACTION TychoAction = Tycho->PlayerCalled();
    if(TychoAction.isTalking){
            // He wants to say something (lamo)
            screen->CreateTimedWindow(
                Tycho->name,
                TychoAction.caption,
                "assets/images/TYCHO/TYCHO_DICE_C.ppm",
                TychoAction.seconds
            );
    }
}

void D_fold(){

}

void D_raise(){

}

int main(){
    // Create Players
    Tycho = new Poker::Player("Tycho Brahe", false, "assets/dialog/Tycho.json");
    //Heavy = new Poker::Player("The Heavy", false);
    

    // Create inputMan
    Input::InputManager* inputMan = new Input::InputManager();

    // Create screen
    screen = new Graphics::Screen("Poker Night at the Terminal");


    // Create choice window
    Graphics::Window choicesWindow("Choices:", 10, 10, 40, 10);
    Graphics::Text choiceText("Choices:", 2, 2);
    Graphics::Button fold("FOLD", 5, 5, 6, 2, D_fold);
    Graphics::Button call("CALL", 17, 5, 6, 2, D_call);
    Graphics::Button raise("RAISE", 27, 5, 6, 2, D_raise);

    // Create table
    Graphics::Image tableImage("assets/images/damn30.ppm", 0, 0);
    Graphics::Window tableWindow("View", 60, 5, tableImage.width, tableImage.height);
    tableWindow.AddImage(&tableImage);
    

    choicesWindow.AddText(&choiceText);
    choicesWindow.AddButton(&fold); 
    choicesWindow.AddButton(&call); 
    choicesWindow.AddButton(&raise); 

    // Add it
    screen->AddWindow(&tableWindow);
    screen->AddWindow(&choicesWindow);
    


    screen->Display();

    std::thread TychoWork(T_Update);
    TychoWork.detach();
    std::thread goof(updateInput, choicesWindow, inputMan);
    goof.detach();
    while(1){
        screen->Refresh();
    }
    
    return 0;
}