/*
*/
#include "diag_options.h"

Character::Diag_Options::Diag_Options(){

}

std::string Character::Diag_Options::getRandom(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,dataText.size());
    return dataText[dist6(rng)];
}