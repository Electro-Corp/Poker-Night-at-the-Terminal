/*

*/
#ifndef INPUTMAN_H
#define INPUTMAN_H
#include "keyboard.h"
#include "mouse.h"

#include <ncurses.h>

namespace Input{


    class InputManager{
        private:
            Keyboard keyboard;
        public:
            InputManager();

            char InputTick();
    };
}
#include "inputmanager.cpp"
#endif