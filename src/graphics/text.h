/*
    Text
*/
#ifndef TEXT_H
#define TEXT_H
#include <iostream>
namespace Graphics{
    class Text{
        private:
        public:
            std::string text;
            int x, y;
            Text(std::string text, int x, int y);
    };
}
#include "text.cpp"
#endif