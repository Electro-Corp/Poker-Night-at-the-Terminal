/*

*/
#ifndef CHAR_H
#define CHAR_H
#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <json/json.h>

#include "diag_options.h"
#include "../graphics/image.h"

namespace fs = std::filesystem;

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

            //
            std::vector<Graphics::Image*> images;

            Character(std::string dataFilePath, std::string);

    };
}
#include "character.cpp"
#endif