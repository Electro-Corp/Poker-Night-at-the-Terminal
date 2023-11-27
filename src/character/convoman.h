/*
    Manages conversations
*/
#ifndef CONVOMAN_H
#define CONVOMAN_H
#include <iostream>
#include <filesystem>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

#include "../utils/JsonReader.h"
#include "../poker/player.h"
#include "../graphics/screen.h"

namespace fs = std::filesystem;
using namespace std::this_thread;
using namespace std::chrono_literals; // ns, us, ms, s, h
using std::chrono::system_clock;
/*
*/
namespace Character{
    /*
        Stores a single dialog line
    */
    class DialogLine{
        private:
        public:
            std::string line, speaker;
            DialogLine(std::string, Json::Value line);
    };

    /*
        Stores a conversation
    */
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
            std::random_device dev;
        public:
            std::vector<Poker::Player*> chars;
            std::vector<Conversation> convos;

            ConversationManager(std::string convoDir, std::vector<Poker::Player*> players);
            ConversationManager();


            void ConversationTick(Graphics::Screen* screen);
    };
}
#include "convoman.cpp"
#endif