#include <iostream>
#include "Bag.h"
using namespace std;

////////////////////////////////////////////////////////////////////

void Bag::insert(Item a) {
   vec.push_back(a);
 for(unsigned int i=0; i<vec.size() - 1; i++) {
  if (vec[vec.size()-1].elem == vec[i].elem) {
    vec[i].freq++;
    vec.pop_back();
  }
}
}
vector<Item> Bag::getItems() const
{
    vector<Item> v;
    for(unsigned i=0; i<vec.size(); i++)
        v.push_back(vec[i]);
    return v;
}


ostream& operator<<(std::ostream& s, const Bag& b)
{

    for(unsigned i=0; i<b.vec.size(); ++i){
        s<<"("<<b.vec[i].elem<<","<<b.vec[i].freq<<")"<<endl;
    }
    return s;
}

//////////////////////////////////////////////////////////////////////
Item Bag::findMax() throw (bagError) {

    if(vec.size() ==0 ) throw EMPTY_BAG;
    int maxi = 0;
    for(unsigned int i = 1; i<vec.size(); i++) {
        if (vec[i].elem > vec[maxi].elem) {
            vec[maxi] = vec[i];
        }
    }

   return Item(vec[maxi]);
}


//////////////////////////////////////////////////////////////////////
int Bag::frequency(int el) {
   for(unsigned int i = 0; i<vec.size(); i++) {
     if(el == vec[i].elem) {
        return vec[i].freq;
        break;
      }
   }

}

//////////////////////////////////////////////////////////////////////
Item Bag::remove(int rm) throw (bagError) {
  Item removed;
  int cnt1 = 0;
  for(unsigned int i=0; i<vec.size(); i++) {
     if(rm == vec[i].elem) {
         removed = vec[i];
         vec[i]=vec[vec.size()-1]; // put the last element to the index of the removed element
         vec.pop_back();
         cnt1++;
     }
  }
 if(cnt1 == 0 ) throw INVALID_ELEMENT;
     return removed;
}
