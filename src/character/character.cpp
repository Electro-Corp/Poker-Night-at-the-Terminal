/*
*/
#include "character.h"

#include "../utils/JsonReader.h"

Character::Character::Character(std::string fPath, std::string imagePath){
    // Load shit
    JsonReader cR(fPath.c_str());

    Json::Value cRVals = cR.read();
    
    for(auto& pCheckString : cRVals["Checking"]["Player_Checks"]){
        this->Player_Checks.dataText.push_back(
            pCheckString.asString()
        );
    }

    for(auto& tCheckString : cRVals["Checking"]["This_Checks"]){
        this->Checking.dataText.push_back(
            tCheckString.asString()
        );
    }

    for(auto& tCallString : cRVals["Calling"]["This_Calls"]){
        this->Calling.dataText.push_back(
            tCallString.asString()
        );
    }

    for(auto& pCallString : cRVals["Calling"]["Player_Calls"]){
        this->Player_Calls.dataText.push_back(
            pCallString.asString()
        );
    }

    // Load images
    for (const auto & entry : fs::directory_iterator(imagePath)){
        Graphics::Image* tmp = new Graphics::Image(entry.path().u8string(), 0, 0);
        this->images.push_back(tmp);
    }
}