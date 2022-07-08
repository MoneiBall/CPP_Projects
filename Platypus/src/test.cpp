#include "test.h"
#include "platypus.h"
#include <iostream>
using namespace std;


// Class Testing: You must test your Platypus class thoroughly in your
// driver program.
// A default constructor for the Test suite.
Test::Test(){
    test1();
    test2();
    test3();
};


void Test::test1(){
    cout<<"\n******************* Test 1 *******************\n"<<endl;
    Platypus p1('m',1.5, 3, 'A');
    Platypus p2('f',2.2, 7, 'B');

    cout<<"Battle started between \""<< p1.getName() << "\" and " << p2.getName()<<endl;
    (&p1)->fight(p2);
    (&p2)->fight(p1);
    (&p1)->fight(p2);

    p1.print();
    p2.print();
};


void Test::test2(){
    //Test eat(), hatch(), age_me() functions ...
    cout<<"\n******************* Test 2 *******************\n"<<endl;
    Platypus p1;
    p1.print();
    p1.hatch();
    cout<<"Platypus \""<< p1.getName() << "\" hatched. "<<endl;
    p1.print();
    p1.eat();
    cout<<"Platypus \""<< p1.getName() << "\" ate and grew. "<<endl;
    p1.print();
    p1.age_me();
    cout<<"Platypus \""<< p1.getName() << "\" aged. "<<endl;
    p1.print();

    Platypus p2;
    p2.age_me();

    Platypus p3('f',2.12, 2, 'M');
    p3.print();
    p3.age_me();
    cout<<"Platypus \""<< p3.getName() << "\" aged. "<<endl;
    p3.print();

};


void Test::test3(){
    //Test setters and getters
    cout<<"\n******************* Test 3 *******************\n"<<endl;
    Platypus p1('f',5.55, 12, 'Z');
    p1.print();
    cout<<"Is platypus \""<< p1.getName() << "\" mutant? - " << (p1.getMutant() ? "true" : "false")<<"."<<endl;
    cout<<"Platypus \""<< p1.getName() << "\" age, gender, mutation were set. "<<endl;
    p1.setAge(5); p1.setGender('m'); p1.setMutant(true);
    cout<<"Is platypus \""<< p1.getName() << "\" mutant? - " << (p1.getMutant() ? "true" : "false")<<"."<<endl;

    p1.print();
    cout<<"\n";
};