/*
    Container for Dialog options 
*/
#ifndef DIAG_OPTION_H
#define DIAG_OPTION_H
#include <iostream>
#include <vector>
namespace Character{
    class Diag_Options{
        public:
            std::vector<std::string> dataText;

            Diag_Options();

            std::string getRandom();
    };
}
#include "diag_options.cpp"
#endif