#include <iostream>
#include "day.h"
#include "animal.h"

using namespace std;

// implementation of class Blue
Blue* Blue::_instance = nullptr;
Blue* Blue::instance()
{
    if(_instance == nullptr) {
        _instance = new Blue();
    }
    return _instance;
}
void Blue::destroy()
{
    if ( nullptr!=_instance ) delete _instance;
}
//--------------------------------------------------------------------------
Day* Blue::swing()
{
    return Usual::instance();
}
//--------------------------------------------------------------------------
void Blue::updatePower(Tarantula *p)
{
    p->changePower(-3);
}

void Blue::updatePower(Hamster *p)
{
    p->changePower(-5);
}

void Blue::updatePower(Cat *p)
{
    p->changePower(-7);
}
//---------------------------------------------------------------------------

// implementation of class Usual
Usual* Usual::_instance = nullptr;
Usual* Usual::instance()
{
    if(_instance == nullptr) {
        _instance = new Usual();
    }
    return _instance;
}
void Usual::destroy()
{
    if ( nullptr!=_instance ) delete _instance;
}
//-------------------------------------------------------------------------------------------
Day* Usual::swing()
{
    return Joyful::instance();
}
//--------------------------------------------------------------------------------------------
void Usual::updatePower(Tarantula *p)
{
    p->changePower(-2);
}

void Usual::updatePower(Hamster *p)
{
    p->changePower(-3);
}

void Usual::updatePower(Cat *p)
{
    p->changePower(3);
}
//---------------------------------------------------------------------------------------------

// implementation of class Joyful
Joyful* Joyful::_instance = nullptr;
Joyful* Joyful::instance()
{
    if(_instance == nullptr) {
        _instance = new Joyful();
    }
    return _instance;
}
void Joyful::destroy()
{
    if ( nullptr!=_instance ) delete _instance;
}
//--------------------------------------------------------------------------------
Day* Joyful::swing()
{
    return this;
}
//--------------------------------------------------------------------------------

void Joyful::updatePower(Tarantula *p)
{
    p->changePower(1);
}

void Joyful::updatePower(Hamster *p)
{
    p->changePower(2);
}

void Joyful::updatePower(Cat *p)
{
    p->changePower(3);
}
//--------------------------------------------------------------------------------
