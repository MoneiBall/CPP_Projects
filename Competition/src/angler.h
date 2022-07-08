#pragma once

#include "championship.h"
#include <string>

struct Angler {
    std::string name;
    int contest_cnt;
};


class AnglerEnor{
    public:
        AnglerEnor(const std::string &str): _tt(str) { };
        void first() {_tt.first(); next();}
        void next();
        Angler current() const { return _cur;}
        bool end() const { return _end;}


     private:
        Angler _cur;
        ChampEnor _tt;
        bool _end;
};

