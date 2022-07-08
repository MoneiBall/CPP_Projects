#pragma once
#include "read.hpp"
#include "polynomial.h"
#include <sstream>

class Menu
{
    public:
        void run();
        int printMenu();
        void add_polynomials();
        void multiply_polynomials();
        void evaluate_polynomial();
};