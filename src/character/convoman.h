/*
    Manages conversations
*/
#ifndef CONVOMAN_H
#define CONVOMAN_H
#include <iostream>
#include <filesystem>
#include <vector>

#include "../utils/JsonReader.h"
#include "../poker/player.h"
#include "../graphics/screen.h"

namespace fs = std::filesystem;

namespace Character{
    class DialogLine{
        private:
        public:
            std::string line, speaker;
            DialogLine(std::string, Json::Value line);
    };

    class Conversation{
        private:
            
        public:
            std::vector<DialogLine> lines;
            Conversation(Json::Value conversation);
    };
    
    /*
        Manages conversations between the 
        AI players
    */
    class ConversationManager{
        private:
        public:
            std::vector<Poker::Player> chars;
            std::vector<Conversation> convos;

            ConversationManager(std::string convoDir);
            ConversationManager();


            void ConversationTick(Graphics::Screen* screen);
    };
}
#include "convoman.cpp"
#endif