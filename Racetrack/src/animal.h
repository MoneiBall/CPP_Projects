#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "day.h"

// class of the abstract animals
class Animal{
protected:
    std::string _name;
    int _power;
    Animal (const std::string &str, int e = 0) :_name(str), _power(e) {}
public:
    std::string getName() const { return _name; }
    int getPower() {return _power;}
    bool isAlive() const { return _power > 0; }
    void changePower(int e) { _power += e; }

    virtual void updatePower(Day* &mood) = 0;
    virtual ~Animal () {}
};



// class of Tarantulas
class Tarantula : public Animal {
public:
    Tarantula(const std::string &str, int e = 0) : Animal(str, e){}
   void updatePower(Day* &mood) override {
        mood -> updatePower(this);
    }

};

// class of Hamsters
class Hamster : public Animal {
public:
    Hamster(const std::string &str, int e = 0) : Animal(str, e){}
    void updatePower(Day* &mood) override {
        mood ->updatePower(this);
    }

};

// class of Cats
class Cat : public Animal {
public:
    Cat(const std::string &str, int e = 0) : Animal(str, e){}
    void updatePower(Day* &mood) override{
        mood ->updatePower(this);
    }

};


