#include <iostream>
#include <string>
#include <fstream>
#include "order_class.h"

using namespace std;


//Name: default constructor
//Precondition: Plant data has not been initialized yet
//Postcondition: Plant data has been initialized into a dynamic array
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records, STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.
order_class::order_class()
{
    count = 0;
    size = 1;
    STR = new order_record[size];
    ifstream in;
    in.open("nursery_stock.txt");
    if(in.fail())
    {
        cout << "File did not open correctly" << endl;
    }
    while(!in.eof())
    {
        if(is_full())
        {
            double_size();
        }
        in >> STR[count].pname;
        in >> STR[count].cname;
        in >> STR[count].plant_cost;
        in >> STR[count].quantity;
        
        count++;
    }
    
    cout << "The default constructor has been called\n";
    in.close();
}


//Name: copy constructor
//Precondition: Dynmaic array has not been copyed into org
//Postcondition: Dynamic copy has been copyed into org
//Description:  The function performs a deep copy of the formal parameter org.
order_class::order_class(const order_class& org)
{
    STR = new order_record[size];
    count = org.count;
    
    for(int i = 0; i < org.count; i++)
    {
        STR[i] = org.STR[i];
    }

}


//Name: is_Empty
//Precondition: Checking if STR is empty depending on count
//Postcondition: The function has returned true or false depending on the data in count
//Decription: returns true if STR is empty
bool order_class::is_Empty()
{
    if(count == 0)
    {
        return true;
    }
    return false;
}

//Name: is_full
//Precondition: Function is being used to see if the count is equivalent to size
//Postcondition: If count is equal to size it is returned true otherwise it will be returned false
//Decription: returns true if STR is full
bool order_class::is_full()
{
    if(count == size)
    {
        return true;
    }
    return false;
}

//Name: search
//Precondition: Location of key needs to be located from the dynamic array
//Postcondition: Data has either been located or a -1 has been returned
//Decription: locates key in STR if it is there; otherwise -1 is returned
int order_class::search(const string key)
{
    for(int i = 0; i < count; i++)
    {
        if(STR[i].pname == key)
        {
            return i;
        }
    }
    return -1;
}

//Name: add
//Precondition: Dynamic array has been filled with data from the input file
//Postcondition: Plant data has been added to the array
//Decription: adds a order_record to STR; if STR is full, double_size is called to increase the size of STR. The user is prompted to enter the plant name, county name, plant cost and quantity.
void order_class::add( )
{
    if(is_full())
    {
        double_size();
    }
    cout << "Enter plant name:";
    cin >> STR[count].pname;
    cout << "Enter county name:";
    cin >> STR[count].cname;
    cout << "Enter plant cost:";
    cin >> STR[count].plant_cost;
    cout << "Enter quantity:";
    cin >> STR[count].quantity;
    count++;
    process();
}

//Name: operator-
//Precondition: Specific data from key has not been removed
//Postcondition: Data has been removed
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
order_class& order_class::operator-(const string key)
{
    int loc = search(key);
    
    if(loc != -1)
    {
        for(int i = loc; i < count; i++)
        {
            if(STR[i].pname == key)
            {
                for(int j = i; j < count - 1; j++)
                {
                    STR[i] = STR[i + 1];
                }
                count--;
            }
        }
    }
    
    return *this; //returning the current object
}

//Name: double_size
//Precondition: The STR dynamic array is to small and needs to be increased to fit more data.
//Postcondition: The size of the dynamic array has been increased in order to fit more data
//Decription: doubles the size (capacity) of STR
void order_class::double_size( )
{
    size *=2;
    order_record *temp = new order_record[size];

    for(int i=0; i<count; i++)
    {
        temp[i] = STR[i];
    }

    delete [ ] STR;
    STR = temp;
}


//Name: process
//Precondition: Input needs to calculated
//Postcondition: Input has now been calculated and is ready to be outputed to the output file
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.
void order_class::process()
{
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    for(int i = 0; i < count; i++)
    {
        if(STR[i].cname == "dade")
        {
            STR[i].tax_rate = 0.065;
        }
        else if(STR[i].cname == "broward")
        {
            STR[i].tax_rate = 0.06;
        }
        else if(STR[i].cname == "palm")
        {
            STR[i].tax_rate = 0.07;
        }
    
        STR[i].net_cost = STR[i].plant_cost * STR[i].quantity;
    
        if(STR[i].quantity > 50)
        {
            STR[i].discount = 0.13;
        }
        else if(STR[i].quantity >= 21 && STR[i].quantity <= 50)
        {
            STR[i].discount = 0.08;
        }
        else if(STR[i].quantity >= 12 && STR[i].quantity <= 20)
        {
            STR[i].discount = 0.05;
        }
        else if(STR[i].quantity >= 6 && STR[i].quantity <= 11)
        {
            STR[i].discount = 0.03;
        }
        else if(STR[i].quantity >= 1 && STR[i].quantity <= 5)
        {
            STR[i].discount = 0.01;
        }
        else
        {
            STR[i].discount = 0;
        }
    
        STR[i].discount = STR[i].net_cost * STR[i].discount;
    
        STR[i].purchase_tax = STR[i].net_cost * STR[i].tax_rate;
    
        STR[i].total_cost = STR[i].net_cost + STR[i].purchase_tax - STR[i].discount;
    }
}


//Name: operator<<
//Precondition: Data has been processed
//Postcondition: Data has been outputed to the screen
//Decription: prints every field of every call_record in STR formatted to a file and return the stream.
ostream& operator<<(ostream& out, order_class & org)
{
    
    static int run = 1;

    for(int i = 0; i < org.count; i++)
    {
        out << left << setw(15) << org.STR[i].pname;
        out << right << setw(10) << org.STR[i].cname;
        out << right << setw(7) << org.STR[i].plant_cost;
        out << right << setw(6) << org.STR[i].quantity;
        out << right << setw(8) << org.STR[i].net_cost;
        out << right << setw(9) << setprecision(3) << org.STR[i].tax_rate;
        out << right << setw(9) << setprecision(2) << org.STR[i].purchase_tax;
        out << right << setw(9) << org.STR[i].discount;
        out << right << setw(9) << org.STR[i].total_cost << endl;
    }

    out << "****************************\n";
    out << "*********end of run " << run << "****" << endl;
    out << "*******************************\n";
    run++;
    return out;//returning object that invoked the function
}

//Name: destructor
//Precondition: Memory is still allocated to the dynmaic array SRT
//Postcondition: Memory from the dynamic array STR has been de-allocated
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called (automatically by the compiler) before the program is exited.
order_class::~order_class()
{
    delete[] STR;
}



