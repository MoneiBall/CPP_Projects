#pragma once

#include "read.hpp"
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

inline bool notNegative(int a){
    return a >= 0;
}

inline bool valid(int a){
    return true;
}

struct Term
{
    int coefficient;
    int exponent;

    Term() {};
    Term(int c,int e): coefficient(c), exponent(e) {}

    friend std::istream& operator>>(std::istream& s, Term & t)
    {
        t.coefficient=read <int>("Coefficient type has to be an integer!", valid);
        t.exponent=read <int>("Exponent type has to be a positive integer!", notNegative);
        return s;
    }
};
 
class Polynomial{
public:
   static const int maxTerms = 100;
   Polynomial(const std::string &);
   ~Polynomial();
   Polynomial operator+( const Polynomial & );
   Polynomial operator*( const Polynomial & );
   Polynomial operator+=( const Polynomial & );
   Polynomial operator*=( const Polynomial & );
   void convertToStandardForm(std::map<int,int>& );
   int evaluate( const int &) const;
   friend std::ostream& operator<<(std::ostream& s, const Polynomial& p);
   Polynomial implement();
private:
   std::string name;
   std::vector<Term> terms;
};