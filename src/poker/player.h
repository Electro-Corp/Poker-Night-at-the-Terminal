/*
*/
#ifndef POKERPLAYER_H
#define POKERPLAYER_H
#include <iostream>
#include <random>
#include "../character/character.h"
namespace Poker{
    typedef struct {
        bool isTalking; // Is the Character talking
        std::string caption; // What the character is saying
        int seconds; // For how long is it up
    } PLAYER_TICK_ACTION;

    class Player{
        private:
            std::random_device dev;
        public:
            std::string name;
            bool isHuman = false, de = false;

            Character::Character* thisChar;

            Player(std::string name, bool isHuman, std::string fPath = NULL);



            // See if this mf has anything to say
            PLAYER_TICK_ACTION Tick();

            // Poker funcs
            void Fold();
            void Call();
            void Raise();

            // The player did something
            PLAYER_TICK_ACTION PlayerCalled();

    };
}
#include "player.cpp"
#endif