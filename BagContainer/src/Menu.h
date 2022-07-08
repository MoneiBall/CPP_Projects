#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "read.hpp"
#include "Bag.h"

class Menu
{
    public:
        void run();
    private:
        int printMenu();
        void printBag();
        void getCount();
        void delete_El();
        void insert_m();
        void getMax();
        void loadTest();
        Bag B;


};



#endif // MENU_H_INCLUDED
