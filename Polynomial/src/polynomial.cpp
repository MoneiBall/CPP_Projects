#include "polynomial.h"
using namespace std;

//The power of any term in a polynomial should be a non negative integer
Polynomial::Polynomial(const std::string &_name): name(_name) {
    this -> implement();
}
Polynomial::~Polynomial(){}

bool isValidNumberOfTerms(int a) {
    return a >= 0 && a <= Polynomial::maxTerms;
}

Polynomial Polynomial::implement() {
    Term term;
    cout << "Insert number of terms in polynomial " << name << ": " << endl;
    string errmsg = "Terms must be number between 0 and " + Polynomial::maxTerms;
    int numberOfTerms = read <int> (errmsg, isValidNumberOfTerms);
    for(int i=0; i<numberOfTerms; i++){
        cout << "Insert a coefficient and exponent of " << i+1<<". term in each line respectively:" << endl;
        cin >> term;
        terms.push_back(term);
    }
    return *this;
}

Polynomial Polynomial::operator+( const Polynomial &p ){
    // append poly terms alltogether
    terms.insert(terms.end(), p.terms.begin(), p.terms.end());
    map<int, int> polyMap;
    for (unsigned int i = 0; i < terms.size(); i++)
        polyMap[terms[i].exponent] += terms[i].coefficient;
    terms.clear();
    convertToStandardForm(polyMap);
    return *this;
}

Polynomial Polynomial::operator*( const Polynomial &p ){
    map<int, int> polyMap;
    int coefficientResult = 0, exponentResult = 0;
    for (unsigned int i = 0; i < terms.size(); i++){
        //skip outer iteration if a coefficient of term of polynomial @terms equals 0
        if (terms[i].coefficient == 0)
            continue;
        for (unsigned int j = 0; j < p.terms.size(); j++){
        //skip inner iteration if a coefficient of term of polynomial @p.terms equals 0
            if(p.terms[j].coefficient == 0)
                continue;
            coefficientResult = terms[i].coefficient * p.terms[j].coefficient; //coefficients multiplied
            exponentResult = terms[i].exponent + p.terms[j].exponent; //exponents added
            polyMap[exponentResult] += coefficientResult; //populate map with pairs [key,value -> exponent,coefficient]
        }   
    }
    terms.clear();
    convertToStandardForm(polyMap);
    return *this;
}

int Polynomial::evaluate(const int& x) const{
    int sum = 0;
    for(unsigned int i = 0; i < terms.size(); i++)
        sum += terms[i].coefficient * pow(x, terms[i].exponent);
    return sum;
}

void Polynomial::convertToStandardForm(map<int,int>& m) {
    // reverse iterator for map
    map<int,int>::reverse_iterator rit;
    for (rit=m.rbegin(); rit!=m.rend(); ++rit)
        terms.push_back(Term(rit->second, rit->first));
}

ostream& operator<<(std::ostream& s, const Polynomial& p) {
    s<<"p = ";
    for(unsigned int i=0; i<p.terms.size(); i++){
        if (p.terms[i].coefficient >= 0) {
            if (p.terms[i].coefficient == 0)
                continue;
            if (i != 0)
                s<<" + ";
        }
        else
            s<<" - ";
        if (p.terms[i].coefficient != 1)
            s<<abs(p.terms[i].coefficient);
        if (p.terms[i].exponent == 0)
            continue;
        s<<"x";
        if (p.terms[i].exponent != 1)
            s<<"^"<<p.terms[i].exponent;
        s<<" ";
    }
    s<<endl;
    return s;
}

Polynomial Polynomial::operator+=( const Polynomial &p ){
   return *this + p;
} 

Polynomial Polynomial::operator*=( const Polynomial &p ){
   return *this * p;
} 