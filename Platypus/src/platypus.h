#pragma once

class Platypus{
    private:
        float weight = 0.0;
        short age = 0;
        char name = '0';
        char gender = '0';
        bool alive;
        bool mutant;
    protected:

    public:
        Platypus();
        Platypus(char, float, short, char);
        void print() const;
        void age_me();
        void fight(const Platypus &) const;
        void eat();
        void hatch();

        float getWeight();
        short getAge();
        char getName();
        char getGender();
        bool getAlive();
        bool getMutant();

        void setWeight(float);
        void setAge(short);
        void setName(char);
        void setGender(char);
        void setAlive(bool);
        void setMutant(bool);
};