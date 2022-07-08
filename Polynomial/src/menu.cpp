#include "menu.h"
using namespace std;

inline bool checkMenuItems(int a) {
    return (a > 0 && a < 5);
}

inline bool checkInteger(int a) {
    return true;
}

void Menu::run() {

  int option;

   do {
    option = printMenu();

        switch(option){
            case 1:
                add_polynomials();
                break;
            case 2:
                multiply_polynomials();
                break;
            case 3:
                evaluate_polynomial();
                break;
            default:
                cout<<"\nProgram exiting ... GoodBye!\n";
                break;
        }
   }
   while(option != 4);

}


int Menu::printMenu() {
    ostringstream s;
    int response;
     cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>\n"
				" 1 - Add polynomials \n"
				" 2 - Multiply polynomials \n"
				" 3 - Evaluate a polynomial \n"
				" 4 - Exit \n"
             ">>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
             "Select from list: ";
    s<<"Selection number must be between 0 and 4!";
    string errmsg=s.str();
    response=read <int> (errmsg,checkMenuItems);

    return response;
}

void Menu::add_polynomials() {
   Polynomial p1("p1"), p2("p2");
   cout << "Result: " << p1 + p2;
}

void Menu::multiply_polynomials() {
   Polynomial p1("p1"), p2("p2");
   cout << "Result: " << p1 * p2;
}

void Menu::evaluate_polynomial() {
    Polynomial p("p");
    string errmsg = "Parameter value must be integer!";
    cout << "Insert parameter value for polynomial: " << endl;
    int value = read <int> (errmsg, checkInteger);
    cout << "Given: [x = " << value << "], " << p;
    cout << "Result: p = " << p.evaluate(value) << endl;
}