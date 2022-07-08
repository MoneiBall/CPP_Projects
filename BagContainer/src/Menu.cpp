#include "Menu.h"
#include <sstream>
#include "Bag.h"
#include "read.hpp"


using namespace std;

bool check(int a) {
    return (a >= 0 && a <= 6);
}

void Menu::run() {

  int option;

   do {
    option = printMenu();

    switch(option){
				case 1:
				    insert_m();
					break;
				case 2:
			        delete_El();
					break;
				case 3:
                    printBag();
					break;
				case 4:
                    getMax();
					break;
				case 5:
                    getCount();
					break;
                case 6:
                    loadTest();
                    break;
				default:
                cout<<"\nGoodbye!\n";
                break;
			}
   }
   while(option != 0);

}


int Menu::printMenu() {
    ostringstream s;
    int response;
     cout << "\n>>>>>>>>>>>>> "
                "\n Select from list: "
				"\n 1 - Insert Element to Bag \n"
				" 2 - Remove Element from Bag \n"
				" 3 - Print the Bag \n"
				" 4 - Find Largest element \n"
				" 5 - Get frequency of an element \n"
				" 6 - Load Test \n"
				" 0 - Exit \n"
            ">>>>>>>>>>>>>>  ";
    s<<"Selection number must be between 0 and "<<6<<"!";
    string errmsg=s.str();
    response=read <int> (errmsg,check);

    return response;
}

void Menu::insert_m() {
   Item e;
   cout<<"Insert an element :"<<endl;
   cin>>e;
   B.insert(e);
}

void Menu::getMax() {
    Item maximum;
    bool error = false;
    try{
        maximum = B.findMax();
    }

    catch(Bag::bagError err)
    {
        error =true;

        if(err==Bag::EMPTY_BAG)
            cerr<<"The Bag is empty";
        else
            cerr<<"Program error \n";
    }
    if (!error) {
        cout<<"Maximum element pair is : "<<maximum<<endl;
    }
}

void Menu::getCount() {

   int el;
   cout << "In order to get frequency , Enter the element :"<<endl;
   cin>>el;
   cout<< "Frequency of element " <<el<<" is : "<<B.frequency(el);
}

void Menu::delete_El() {
    int rm;
    Item e;
    bool error = false;
    try{
        cout<< "Enter the element you want to remove : ";
        cin >> rm;
        e = B.remove(rm);
    }

    catch(Bag::bagError err)
    {
        error = true;

        if(err == Bag::INVALID_ELEMENT)
            cerr<<"No such element exists in the bag!";
        else
            cerr<<"Program error.";
    }
    if (!error) cout<<"Pair "<<e<<" removed successfully."<<endl;

}

void Menu::loadTest()
{
    const int bound = 100000;
    Bag B;
    cout<<"The number of items in the Bag :\n";
    try{
        for(int i=1; i<bound; i++)
        {

            if(i%1000==0) {
                    cout<<i<<endl;
            }
              B.insert(Item(i,1));
        }
    }catch(...)
    {
        cerr<<"Not enough memory\n";
    }
}

void Menu::printBag() {
    std::cout<<B;
}

