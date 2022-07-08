#include <iostream>
#include "read.hpp"
#include "Bag.h"
#include "Menu.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

   Menu test;
   test.run();

   return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Bag.h"

// Test cases

TEST_CASE("isEmpty()","[Bag]")
{
    Bag B1;
    CHECK( B1.isEmpty() == true );

    Item e(1,1);
    B1.insert(e);
    CHECK( B1.isEmpty() == false );

    e = B1.remove(1);
    CHECK( B1.isEmpty() == true );
}

TEST_CASE("insert","[Bag]")
{
    Bag B;
    Item e1(1,1); Item e2(2,1); Item e3(3,1); Item e4(4,1); Item e5(5,1); Item e6(2,1);

    {
        B.insert(e1);
        CHECK( 1 == B.getLength());
        vector<Item> v = B.getItems();
        CHECK( v[0] == e1);
    }

    {
        B.insert(e2);B.insert(e3);B.insert(e4);B.insert(e5);
        CHECK( 5 == B.getLength());
        vector<Item> v = B.getItems();
        CHECK( e1 == v[0]); CHECK( e2 == v[1]); CHECK( e3 == v[2]); CHECK( e4 == v[3]); CHECK( e5 == v[4]);
        //inserting same element
        B.insert(e6);
        CHECK( 5 == B.getLength());
        v = B.getItems();
        CHECK( e1 == v[0]); CHECK(e2.elem == v[1].elem); CHECK( e3 == v[2]); CHECK( e4 == v[3]); CHECK( e5 == v[4]); CHECK(e6.elem == v[1].elem);
        CHECK( 2 == e2.elem);
    }


}

TEST_CASE("Max [Bag]")
{
    SECTION("Empty Bag")
    {
        Bag B;
        CHECK_THROWS (B.findMax());
    }



    Item e; Item e1(1,1); Item e2(2,2); Item e3(3,1); Item e4(4,3); Item e5(5,2);

    SECTION("one item")
    {
        Bag B;
        B.insert(e1);
        CHECK(e1 == B.findMax());
        e = B.findMax();
        CHECK( e == e1 );

        e = B.remove(e1.elem);
        CHECK( 0 == B.getLength());
        CHECK( e == e1);
  }


    SECTION("Multiple items")
    {
        Bag B;
        B.insert(e5); B.insert(e4); B.insert(e2); B.insert(e3);
        CHECK(e5 == B.findMax());

        e = B.findMax();
        CHECK(e == e5);
        e = B.remove(e5.elem);

        CHECK(3 == B.getLength());
        CHECK(e == e5);

        vector<Item> v = B.getItems();

        CHECK(v[0] == e3); CHECK(v[1] == e4); CHECK(v[2] == e2);

        e = B.findMax();
        CHECK(e == e4);
    }
}
TEST_CASE("Frequency" , "[Bag]") {

       Item e1(1,1); Item e2(2,1); Item e3(1,1);

       Bag B;
       B.insert(e1); B.insert(e2);
       CHECK(1 == B.frequency(e2.freq));

       B.insert(e3); //Inserting same element
       CHECK(2 == B.frequency(e1.freq));

       B.remove(e1.elem);
       CHECK(0 == B.frequency(e1.freq));

}

TEST_CASE("Remove" , "[Bag]") {


      SECTION("Invalid Element")
    {
        Bag B;
        Item e1(2,1);
        CHECK_THROWS (B.remove(2));
        B.insert(e1);
        CHECK_THROWS (B.remove(5));

    }

     SECTION("Multiple Items")
    {
        Bag B;
        Item e1(3,2); Item e2(2,3); Item e3(4,1);
        B.insert(e1); B.insert(e2); B.insert(e3);

        B.remove(e2.elem);
        CHECK(2 == B.getLength());

        vector<Item> v = B.getItems();
        CHECK(v[0] == e1);
        CHECK(v[1] == e3);

        B.remove(e1.elem);
        CHECK(1 == B.getLength());
        v = B.getItems();
        CHECK(v[0] == e3);
    }
}


#endif








