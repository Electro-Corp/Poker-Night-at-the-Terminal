/*

*/
#ifndef CHAR_H
#define CHAR_H
#include <iostream>
#include <fstream>
#include <json/json.h>

#include "diag_options.h"
namespace Character{
    class Character{
        private:
            
        public:
            /*
                Dialog
            */
            // Actions the CPU does
            Diag_Options Betting;
            Diag_Options Raising;
            Diag_Options Checking;
            Diag_Options Calling;
            // Actions other Players do
            Diag_Options Player_Checks;
            Diag_Options Player_Calls;
            Character(std::string dataFilePath);

    };
}
#include "character.cpp"
#endif