// This program demonstrates a destructor.
/**************************************************************
 *                          NOTES                             *
 * -----------------------------------------------------------*
 * • A destructor is a member function that is automatically  *
 *   called when an object is destroyed.                      *
 *                                                            *
 * • Like constructors, destructors have no return type.      *
 *                                                            *
 * • Destructors cannot accept arguments, so they never have  *
 *   a parameter list.                                        *
 **************************************************************/
#include <iostream>
using namespace std;

class Demo
{
public:
    Demo();  // Constructor prototype
    ~Demo(); // Destructor prototype
};

// Constructor
Demo::Demo() // This will execute automatically when object is created
{
    cout << "Welcome to the constructor!\n";
}

// Destructor
Demo::~Demo() // This will execute automatically when object is destroyed
{
    cout << "The destructor is now running.\n";
}

int main()
{
    cout << endl;
    Demo demoObject;
    cout << "This program demonstrates an object\n";
    cout << "with a constructor and destructor.\n";
    return 0;
}