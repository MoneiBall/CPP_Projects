#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

struct Contest {
    std::string angler;
    std::string championship;
    bool exist;
};

class ChampEnor{
    public:
        ChampEnor(const std::string &str) { 
            _f.open(str.c_str()); if (_f.fail()) {
                std::cerr << "Failed to open file '" << str << "' for writing\n"; exit(-1);
            }
        };
        void first() {next();}
        void next();
        Contest current() const { return _cur;}
        bool end() const { return _end;}
    private:
        Contest _cur;
        std::ifstream _f;
        bool _end;
};

