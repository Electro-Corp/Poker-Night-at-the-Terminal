/*
*/
#include "player.h"

Poker::Player::Player(std::string name, bool isHuman){
    this->name = name;
    this->isHuman = isHuman;
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
        tmp.caption = "It's important for you to know up front that I've got your ass kicked preemptively.";
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