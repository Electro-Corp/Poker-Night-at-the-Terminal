/*
*/
#include "convoman.h"

Character::DialogLine::DialogLine(std::string talker, Json::Value val){
    this->speaker = talker;
    this->line = val.asString();
}

Character::Conversation::Conversation(Json::Value conversation){
    int c = 0;
    for(auto& line : conversation){
        std::string uniq = conversation.getMemberNames()[c++];

        DialogLine tmp(uniq.substr(0, uniq.find("_")), line);
        this->lines.push_back(tmp);
    }
}


Character::ConversationManager::ConversationManager(std::string convoDir){
    for (const auto & entry : fs::directory_iterator(convoDir)){
        // Load a file (awesome)
        JsonReader tmp(entry.path().u8string());
        Json::Value val = tmp.read();

        for(auto& convo : val){
            Conversation conv(convo);
            convos.push_back(conv);
        }
    }
}

/*
    
*/
void Character::ConversationManager::ConversationTick(Graphics::Screen* screen){
    // Start
    
}