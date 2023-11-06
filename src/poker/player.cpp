/*
*/
#include "player.h"

Poker::Player::Player(std::string name, bool isHuman, std::string fPath = NULL){
    this->name = name;
    this->isHuman = isHuman;

    if(!isHuman){
        this->thisChar = new Character::Character(
            fPath
        );
    }
}

Poker::PLAYER_TICK_ACTION Poker::Player::Tick(){
    PLAYER_TICK_ACTION tmp = {
        false,
        "",
        0
    };
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(100,500);
    if(dist6(rng) > 150 && de == false){
        de = true;
        // We would like to say something
        tmp.isTalking = true;
        if(this->thisChar)
            tmp.caption = this->thisChar->Checking.getRandom();
        else
            tmp.caption = "What the fuck am I supposed to say?";
        tmp.seconds = 3;
    }
    return tmp;
}

void Poker::Player::Call(){

}

void Poker::Player::Fold(){

}

void Poker::Player::Raise(){

}



/*
    The player did something
*/
Poker::PLAYER_TICK_ACTION Poker::Player::PlayerCalled(){
    PLAYER_TICK_ACTION tmp = {
        true,
        this->thisChar->Player_Calls.getRandom(),
        1
    };
    return tmp;
}