/*
    Keyboard input
*/
#ifndef KEYB_H
#define KEYB_H
#include <iostream>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h> 
#include <ncurses.h>


namespace Input{
    class Keyboard{
        private:
            struct termios oldt, newt;
        public:
            Keyboard();

            char getKey();

            ~Keyboard();
            
    };
}
#include "keyboard.cpp"
#endif