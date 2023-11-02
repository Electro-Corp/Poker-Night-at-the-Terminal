/*
*/
#include "inputmanager.h"


Input::InputManager::InputManager(){

}

char Input::InputManager::InputTick(){
    return this->keyboard.getKey();
}