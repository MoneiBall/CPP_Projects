#pragma once
#include <string>

class Tarantula;
class Hamster;
class Cat;

// class of the abstract days
class Day{
public:
   // virtual void print() {}
    virtual void updatePower(Tarantula *p) = 0;
    virtual void updatePower(Hamster *p) = 0;
    virtual void updatePower(Cat *p) = 0;
    virtual Day* swing() = 0;

    virtual ~Day() {}
};

// class of Blue
class Blue : public Day
{
public:
    //void print() override {std::cout<<"I am blue"<<std::endl;}
    static Blue* instance();
    void updatePower(Tarantula *p) override;
    void updatePower(Hamster *p) override;
    void updatePower(Cat   *p) override;
    Day* swing() override;

    static void destroy() ;
protected:
    Blue(){}
private:
    static Blue* _instance;
};

// class of Usual
class Usual : public Day
{
public:
    //void print() override {std::cout<<"I am Usual"<<std::endl;}
    static Usual* instance();
    void updatePower(Tarantula *p) override;
    void updatePower(Hamster *p) override;
    void updatePower(Cat   *p) override;
    Day* swing() override;

    static void destroy() ;
protected:
    Usual(){}
private:
    static Usual* _instance;
};

// class of Joyful
class Joyful : public Day
{
public:
    //void print() override {std::cout<<"I am Joyful"<<std::endl;}
    static Joyful* instance();
    void updatePower(Tarantula *p) override;
    void updatePower(Hamster *p) override;
    void updatePower(Cat   *p) override;
    Day* swing() override;

    static void destroy() ;
protected:
    Joyful(){}
private:
    static Joyful* _instance;
};

