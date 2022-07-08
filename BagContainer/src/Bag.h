#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED

#include "read.hpp"
#include <string>
#include <iostream>
#include <vector>


inline bool valid(int a){
    return true;
}

struct Item
{
    int elem;
    int freq;

    Item() {};
    Item(int p,int s): elem(p), freq(s) {}

    friend std::istream& operator>>(std::istream& s, Item &e)
    {
        e.elem=read <int>("Element type has to be an integer!",valid);
        e.freq = 1;

        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Item& e)
    {
        s<<"("<<e.elem<<","<<e.freq<<")";
        return s;
    }

    bool operator==(const Item& b)
    {
        return (elem==b.elem && freq==b.freq);
    }

};



class Bag{
public:

    bool isEmpty() {return vec.size()==0;}
    enum bagError{EMPTY_BAG ,INVALID_ELEMENT};
    unsigned int getLength() const {return vec.size();}
    unsigned int getCapacity() const {return vec.capacity();}
    void insert(Item a);
    Item remove(int rm) throw (bagError);
    std::vector<Item> getItems() const;
    friend std::ostream& operator<<(std::ostream& s, const Bag& b);
    Item findMax() throw (bagError);
    int frequency(int el);

private:

    std::vector<Item> vec;
};




#endif // BAG_H_INCLUDED
