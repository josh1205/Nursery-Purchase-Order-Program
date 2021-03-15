// Name: Joshua Lavieri
// Z#: 23477048
// Course: Foundations of Computer Science
// Professor: Dr. Lofton Bullard
// Due Date: 08/03/20
// Total Points: 20
// Assignent#: 11

//Description:

#include <iostream>
#include <string>
#include "order_class.h"

using namespace std;


//Here is your driver to test the program
int main()
{
    order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
    cout << "**********************************************************************\n";
    //Test 1:
    cout << "Test 1: Testing default construcor, double_size, process, is_full and operator<< " << endl;
    myOrders.process();
    cout<<myOrders;
    cout << "End of Test 1" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 2:
    //void add();
    cout << "Test 2: Testing add, double_size, process, is_full, and operator<< " << endl;
    myOrders.add();//test case: pname = rose, cname = dade, plant cost = 1, quantity = 1
    cout<<myOrders;
    cout << "End of Test 2" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 3:
    //operator-(string key);
    cout << "Test 3: Testing operator-, is_Empty, search and opertor<< " << endl;
    cout << "Removing rose\n";
    myOrders -"rose";
    cout<<myOrders;
    cout << "Removing bergenia and yarrow\n";
    myOrders - "bergenia" - "yarrow";
    cout<<myOrders;
    cout << "Removing rose ---AGAIN--- SHOULD GET MESSAGE\n";
    myOrders -"rose";
    cout<<myOrders;
    cout << "End of Test 3" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 4:
    //copy constructor
    cout << "Test4: Testing copy constructor\n\n";
    order_class yourOrders = myOrders;
    cout << yourOrders << endl;
    cout << "End of Test 4" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    //Test 5:
    //destructor will be invoked when object myOrders goes out of scope
    cout << "Test 4: Destructor called" << endl;
    cout << "End of Test 5" << endl;
    cout << "**********************************************************************\n";
    cout << "**********************************************************************\n";
    return 0;
}

