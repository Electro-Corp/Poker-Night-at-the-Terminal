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

        DialogLine tmp((uniq.substr(uniq.find("-") + 1, uniq.find("_") - 2)), line);
        this->lines.push_back(tmp);
    }
}


Character::ConversationManager::ConversationManager(std::string convoDir, std::vector<Poker::Player*> players){
    this->chars = players;
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
    // Since this runs in a seperate thread, we can run through an entire 
    // conversation in a single ConversationTick call
    
    // Check if we should start a convo (random)
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(100,500);
    if(dist6(rng) > 150){
        // ok start a convo

        // choose a random convo    
        std::uniform_int_distribution<std::mt19937::result_type> chooseConvo(0, convos.size());
        Conversation tmp = convos[chooseConvo(rng)];

        // Start running through the conversation

        for(auto& line : tmp.lines){
            std::string path = "assets/images/TYCHO/TYCHO_DICE_C.ppm";

            for(auto& p : chars){
                if(p->name.find(line.speaker) != std::string::npos){
                    path = (p->thisChar->getRandomImage())->imagePath;
                }
            }
            screen->CreateTimedWindow(
                line.speaker,
                line.line,
                path,
                2
            );
            sleep_for(2s);
        }

    }
    // Wait some time before the next conversation
    std::uniform_int_distribution<std::mt19937::result_type> delay(3,10);
    sleep_for(5s);

}