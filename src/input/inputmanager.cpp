/*
*/
#include "inputmanager.h"


Input::InputManager::InputManager(){

}

char Input::InputManager::InputTick(){
    char key = this->keyboard.getKey();
    return key;
}