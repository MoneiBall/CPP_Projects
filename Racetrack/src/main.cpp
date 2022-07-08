//Project : Exhilaration Racetrack (OOP 3rd Assignment)
//Date : 5/11/2019
//Author : Sadi Mamedov LHXOTB
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "animal.h"
#include "day.h"
using namespace std;

/* ---------------------------------------------------------------------------------------------
   Task:          Filling the vector of animals and the racetrack from a file of a given name
   Input:         string str	- name of the text file.
   Output:        vector<Animal*> &animals  - vector of pointers of the animals.
                  vector<Day*> &track - vector of the days of the racetrack.
   --------------------------------------------------------------------------------------------- */

void create(const string &str, vector<Animal*> &animals, vector<Day*> &track)
{
    ifstream f(str);
    if(f.fail()) { cout << "Cannot open the file!\n"; exit(-1);}

    int n; f >> n;
    animals.resize(n);
    for( int i=0; i<n; ++i ){
        char ch; string name; int p;
        f >> ch >> name >> p;
        switch(ch){
            case 'T' : animals[i] = new Tarantula(name, p); break;
            case 'H' : animals[i] = new Hamster(name, p); break;
            case 'C' : animals[i] = new Cat(name, p);   break;
        }
    }

    char type_day;
    while(f >> type_day) {
        switch(type_day){
           case 'b' : track.push_back(Blue::instance());  break;
           case 'u' : track.push_back(Usual::instance());  break;
           case 'j' : track.push_back(Joyful::instance());  break;
        }
    }
}

/* ---------------------------------------------------------------------------------------------
   Task:          Deciding whether all the animals have power greater than 5.
   Input:         vector<Animal*> &animals	- vector of pointers of the animals.
   Output:        l - boolean value obtained due the condition based on vector<Animal> animals
   --------------------------------------------------------------------------------------------- */

bool allOver5 (const vector<Animal*> &animals)
{
    bool l = true;
    for(unsigned int i=0; l && i<animals.size(); i++){
      l = (animals[i]->getPower()>5);
    }
    return l;
}

/* ---------------------------------------------------------------------------------------------
   Task:          Deciding whether any of the animals have a positive power level.
   Input:         vector<Animal*> &animals	- vector of pointers of the animals.
   Output:        l - boolean value obtained due the condition based on vector<Animal> animals
   --------------------------------------------------------------------------------------------- */

bool existsAlive (const vector<Animal*> &animals)
{
    bool l = false;
    for(unsigned int i=0; !l && i<animals.size(); i++){
      l = (animals[i]->isAlive());
    }
    return l;
}


/* ----------------------------------------------------------------------------------------------
   Task:       Surviving racetrack
   Input:      vector<Animal*> &animals  - vector of pointers of the animals
               vector<Day*> &track - vector of the days of the racetrack
   Output:     vector<Animal*> &animals  - vector of pointers of the animals
               vector <string> &highest  - vector of animals having highest power at each round
   Activity:   Owner of the animals checks power levels of each animal, and his mood
               changes the track (vector<Day*> &track), as long as their health condition(>5) holds
               each animal passes the track at each day, if that particular animal is alive.
               If not so, the animal is discarded from the track and others continue. Finally, at the
               end of each day, an animal which have maximum health to be determined.
   ------------------------------------------------------------------------------------------------ */

void race(vector<Animal*> &animals, vector<Day*> &track, vector <string> &highest) {

    for( unsigned int j=0;j < track.size(); j++ ) {
        int max_i = 0;
        if(allOver5(animals))
        track[j] = track[j] ->swing();

            for(unsigned int i=0; i < animals.size(); i++) {
                if(animals[i]->isAlive()){
                animals[i]->updatePower(track[j]);
                  // std::cout<<animals[i]->getName()<<" "<<animals[i]->getPower()<<std::endl;
                    if(animals[i]->getPower() > animals[max_i]->getPower()){ // find maximum power
                        max_i = i;
                    }
                }
            }
                      if(existsAlive(animals)){
                      highest.push_back(animals[max_i]->getName()); // stores in vector of animals
                      }
        }
}


/* ---------------------------------------------------------------------------------------
  Task:       Destruction of the day objects
  Input:      vector<Animal*> &animals - vector of pointers of the animals
  Activity:   destroys every dynamically allocated animal
  ---------------------------------------------------------------------------------------- */

void destroy(vector<Animal*> &animals)
{
    for(auto animal : animals) delete animal;
}


/* ---------------------------------------------------------------------------------------
  Task:       Destruction of the day objects
  Input:      vector<Day*> &track - vector of pointers of the days
  Activity:   destroys every dynamically allocated day
  ---------------------------------------------------------------------------------------- */
void destroyDay()
{
    Blue::destroy();
    Usual::destroy();
    Joyful::destroy();
}

#define NORMAL_MODE1
#ifdef NORMAL_MODE1


int main()
{
    vector<Animal*> animals;
    vector<Day*> track;
    vector<string> highest;
    create("../test_input/input.txt", animals, track);
    race(animals, track, highest);
    for(auto maxi : highest) cout << maxi << endl;

    //Destruction of objects
    destroy(animals);
    destroyDay();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("1","Transmute,ChangePower")
{
    vector<Animal*> animals;
    vector<Day*> track;
    vector<string> highest;

    highest.clear(); track.clear();
    animals.push_back(new Tarantula("Tobi", 1));
    CHECK(animals[0]->isAlive() == true);
    track.push_back(Blue::instance());
    race(animals, track, highest);
    CHECK(animals[0]->isAlive() == false);

    animals.clear();
    track.clear();
    animals.push_back(new Tarantula("Webster", 4));
    track.push_back(Blue::instance()); track.push_back(Usual::instance()); track.push_back(Joyful::instance());
    race(animals, track, highest);

    CHECK(animals[0]->isAlive() == false);
    CHECK(track[0] == Blue::instance());
    CHECK(track[1] == Usual::instance());
    CHECK(track[2] == Joyful::instance());

    destroy(animals);


    animals.clear();
    track.clear();
    animals.push_back(new Cat("Garfield", 5));
    track.push_back(Joyful::instance()); track.push_back(Usual::instance()); track.push_back(Blue::instance());
    race(animals, track, highest);

    CHECK(animals[0]->isAlive() == true);
    CHECK(track[0] == Joyful::instance());
    CHECK(track[1] == Joyful::instance());
    CHECK(track[2] == Usual::instance());

    destroy(animals);


    animals.clear();
    track.clear();
    animals.push_back(new Hamster("Dexter", 10));
    track.push_back(Blue::instance()); track.push_back(Blue::instance()); track.push_back(Blue::instance());
    race(animals, track, highest);

    CHECK(animals[0]->isAlive() == false);
    CHECK(track[0] == Usual::instance());
    CHECK(track[1] == Usual::instance());
    CHECK(track[2] == Blue::instance());
    highest.clear();
    track.clear();

    destroy(animals);

    animals.clear();
    track.clear();
    animals.push_back(new Cat("Cat-Man-Do", 3));
    track.push_back(Joyful::instance()); track.push_back(Blue::instance());
    race(animals, track, highest);

    CHECK(animals[0]->isAlive() == true);
    CHECK(track[0] == Joyful::instance());
    CHECK(track[1] == Usual::instance());

    destroy(animals);


    animals.clear();
    track.clear();
    animals.push_back(new Cat("CJ_McMill", 1));
    track.push_back(Blue::instance()); track.push_back(Joyful::instance());
    race(animals, track, highest);

    CHECK(animals[0]->isAlive() == false);
    CHECK(track[0] == Blue::instance());
    CHECK(track[1] == Joyful::instance());
    highest.clear(); track.clear();

    destroy(animals);
/*   destroyGround();
}
TEST_CASE("2", "length of interval") {

 */
//////////////////////////////////////////////////////////////////////
    create("../test_input/inp11.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest.size() == 0);
    destroy(animals);
    highest.clear(); track.clear();


    create("../test_input/inp12.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest.size() == 10);
    destroy(animals);
    highest.clear(); track.clear();

    create("../test_input/inp13.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest.size() == 10);
    destroy(animals);
    highest.clear(); track.clear();

    create("../test_input/inp14.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest.size() == 3);
    destroy(animals);
    highest.clear(); track.clear();
/*
    destroyDay();

}


TEST_CASE("3", "Outer Loops")
{
    vector<Animal*> animals;
    vector<Day*> track;
    vector<string> highest;
*/
    create("../test_input/inp21.txt", animals, track);
    CHECK(allOver5(animals) == false);
    for(unsigned int i=0;i<animals.size();i++)
    animals[i]->updatePower(track[0]);
    CHECK(allOver5(animals) == false);
    destroy(animals);
    highest.clear(); track.clear();

    create("../test_input/inp22.txt", animals, track);
    CHECK(allOver5(animals) == true);
    for(unsigned int i=0;i<animals.size();i++)
    animals[i]->updatePower(track[0]);
    CHECK(allOver5(animals) == false);
    destroy(animals);
    highest.clear(); track.clear();

    create("../test_input/inp23.txt", animals, track);
    CHECK(existsAlive(animals) == true);
    for(unsigned int i=0;i<animals.size();i++)
    animals[i]->updatePower(track[0]);
    CHECK(existsAlive(animals) == false);
    destroy(animals);
    highest.clear(); track.clear();

    //if tehere exist at least before the race and after the race

    create("../test_input/inp12.txt", animals, track);
    CHECK(existsAlive(animals) == true);
    race(animals, track, highest);
    CHECK(existsAlive(animals) == true);
    destroy(animals);
    highest.clear(); track.clear();

 /*   destroyDay();
}
TEST_CASE("4. MaximumCheck") {

    vector<Animal*> animals;
    vector<Day*> track;
    vector<string> highest;
 */

   //one animal prevails other next round

    create("../test_input/inp31.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest[0] == "Homifomi");
    CHECK(highest[1] == "Garfield");
    destroy(animals);

   //no max element exists
    highest.clear(); track.clear();
    create("../test_input/inp32.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest.size() == 0);
    destroy(animals);


    highest.clear(); track.clear();
    create("../test_input/inp33.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest[9] == "Garfield");
    destroy(animals);

     //last animal is beast
    highest.clear(); track.clear();
    create("../test_input/inp34.txt", animals, track);
    race(animals, track, highest);
    CHECK(highest[4] == "Dexter");
    destroy(animals);

    destroyDay();
}

#endif
