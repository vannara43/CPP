// Vannara Thong CSC5 Chapter 2, p.83, #14
//
/**************************************************************
 *
 * Personal Information
 * ____________________________________________________________
 * This program will compute the personal information
 * such as full name, full address, telephone, and major
 * ____________________________________________________________
 * INPUT
 * fullName                  : Full name of person
 * address                   : Address of person place
 * city                      : City of address
 * state                     : State of address
 * ZIP                       : ZIP Code of city
 * telephone                 : Phone number of person
 * collegeMajor              : Person College Makor
 *
 *
 * OUTPUT
 * fullName                  : Output the full name
 * address, city, state, ZIP : Output the full address
 * telephone                 : Output the telephone
 * collegeMajor              : Output the college major
 *
 **************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string fullName = "Vannara Thong";  // string stores name
    string address = "25658 Main St";   // string stores address
    string city = "Riverside";          // string stores city
    string state = "CA";                // string stores state
    int ZIP = 92507;                    // int stores ZIP
    string telephone = "909-123-1234";  // string stores telephone
    string collegeMajor = "Mathematic"; // string stores college major

    cout << "Full Name: " << fullName << endl;                                                                // Output name
    cout << "Address, City, State, ZIP: " << address << "x, " << city << ", " << state << " " << ZIP << endl; // Output address, city, state, and ZIP
    cout << "Telephone: " << telephone << endl;                                                               // Output telephone
    cout << "College Major: " << collegeMajor << endl;                                                        // Output college major
    cin.get();                                                                                                // wait for any keys to be pressed to end code

    return 0;
}