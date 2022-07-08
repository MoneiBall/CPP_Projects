#include "platypus.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;


// A default constructor that creates a dead duck card.
Platypus::Platypus(){
    this->alive = false;
};

// A parameter constructor that transmits values to specify the values of the object's
// gender, weight, age, and name variables, and by default the object must be alive
// and not mutant.. 
Platypus::Platypus(char gender, float weight, short age, char name){
    this->gender = gender;
    this->weight = weight;
    this->age = age;
    this->name = name;
    this->alive = true;
    this->mutant = false;
};

// Feature print that displays information about the duck card in a beautiful and
// easily comprehensible form and format
void Platypus::print() const{
    cout<<"Platypus {weight = " << weight << ", age = " << age << ", name = " << name << 
    ", gender = " << gender << ", alive = " << (alive ? "true" : "false") << 
    ", mutant = " << (mutant ? "true" : "false") << "}" << endl;
};

// Function age_me which returns nothing but changes the age of the object. It
// should provide for a 2% chance that the object might become a mutant. Each time
// the age_me function is called, the object has a chance to die and this chance is
// equal to 10 times the weight of the duck card, ie a 5 kg duck card has a 50%
// chance of dying. The probability of death of Platypus of 10 and more kilograms
// is 100%.
void Platypus::age_me(){
    //terminate if the duckling is either dead (not alive) or already mutant.
    if(!alive){
        cout<<"Platypus \""<< name << "\" is not Alive!. "<<endl;
        return;
    }

    srand(time(0)); //set current time 0 as seed value
    const float raw = (((float) rand()) / (float) RAND_MAX);
    const float ratio = roundf(raw * 100) / 100;

    if(ratio <= 0.02){
        setMutant(true);
        cout<<"Platypus "<< name << " became mutant. "<<endl;
    }

    if(ratio <= (weight * 10) / 100){
        setAlive(false);
        cout<<"Platypus \""<< name << "\" died. "<<endl;
    }
};

// Function fight- which takes another Platypus as a parameter. Which fights the
// duck card on which the function is called (calling_platypus) against another that
// is passed as a parameter (other_platypus). The winner is determined by the ratio
// of forces ("fight ratio") (calling_platypus weight / other_platypus weight) * 50. A
// random number from 1 to 100 is taken. If the power ratio is greater than this
// random number calling_platypus - wins, otherwise the winner is second.
void Platypus::fight(const Platypus &other) const{
    //terminate if either of two ducklings is dead (not alive).
    if(!alive || !(other.alive))
        return;

    srand(time(0)); //set current time 0 as seed value
    const float fight_ratio = (weight / other.weight) * 50;
    const int random = 1 + (rand() % (99));
    char winner = '0';
    if(fight_ratio > random){
        winner = name;
        // other.setAlive(false);
    }
    else{
        winner = other.name;
        // setAlive(false);
    }
    cout<<"Platypus \"" << winner << "\" won the battle!" <<endl;
};

// The eat function increases the weight of the duck card by 0.1% - 5.0% of its
// current weight
void Platypus::eat(){
    //terminate if duckling is dead (not alive).
    if(!alive)
        return;

    srand(time(0)); //set current time 0 as seed value
    const float raw = (0.1 + 1) + (((float) rand()) / (float) RAND_MAX) * (5.0 - (0.1 + 1));
    const float ratio = roundf(raw * 10) / 10;
    setWeight(weight + weight*ratio);
};

// A hatch function that assigns the newborn Platypus the following parameters
// alive = true, mutant = false, and age = 0. Sex 'm' or 'f' with equal probability.
// Weight randomly from 0.1 to 1.0 kg. The name can be defined by the user or the
// name can be any randomly selected character (character chosen randomly).
void Platypus::hatch(){
    //terminate if duckling is alive.
    if(alive)
        return;

    setAlive(true);
    setMutant(false);
    setAge(0);

    srand(time(0)); //set current time 0 as seed value
    float raw = (float)rand() / RAND_MAX;
    float ratio = roundf(raw * 10) / 10;
    if(ratio > 0.5)
        setGender('f');
    else
        setGender('m');

    raw = 0.1 + (((float) rand()) / (float) RAND_MAX) * (0.9);
    ratio = roundf(raw * 10) / 10;

    setWeight(ratio);

    const char gen_name = 'A' + (rand() % 26); // generate random char letter [A-Z]
    setName(gen_name);
};



//getter functions
float Platypus::getWeight(){ return weight;}
short Platypus::getAge(){ return age;}
char Platypus::getName(){ return name;}
char Platypus::getGender(){ return gender;}
bool Platypus::getAlive(){ return alive;}
bool Platypus::getMutant(){ return mutant;}

//setter functions
void Platypus::setWeight(float weight){ this->weight = weight;}
void Platypus::setAge(short age){ this->age = age;}
void Platypus::setName(char name){ this->name = name;}
void Platypus::setGender(char gender){ this->gender = gender;}
void Platypus::setAlive(bool alive){ this->alive = alive;}
void Platypus::setMutant(bool mutant){ this->mutant = mutant;}

