/*A type cast expression lets you manually promote or demote a value. The general format of a type cast expression is

static_cast<DataType>(Value)

where Value is a variable or literal value that you wish to convert and DataType is the data type you wish to convert Value to. Here is an example of code that uses a type cast expression:

double number = 3.7;
int val;
val = static_cast<int>(number); */

// This program uses a type cast to avoid integer division.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
     // EXAMPLE 1
     cout << setfill('*') << setw(20) << "" << endl;
     cout << setfill(' ') << setw(5) << ""
          << "EXAMPLE 1:" << endl;
     cout << setfill('*') << setw(20) << "" << endl;
     int books;       // Number of books to read
     int months;      // Number of months spent reading
     double perMonth; // Average number of books per month

     cout << "How many books do you plan to read? ";
     cin >> books;
     cout << "How many months will it take you to read them? ";
     cin >> months;
     perMonth = static_cast<double>(books) / months;
     cout << "That is " << perMonth << " books per month." << endl;
     cout << endl;

     // EXAMPLE 2
     cout << setfill('*') << setw(20) << "" << endl;
     cout << setfill(' ') << setw(5) << ""
          << "EXAMPLE 2:" << endl;
     cout << setfill('*') << setw(20) << "" << endl;

     string s = "1023"; // C++11 stoi
     int i = stoi(s);
     cout << i + 100 << endl;

     // EXAMPLE 2
     cout << setfill('*') << setw(20) << "" << endl;
     cout << setfill(' ') << setw(5) << ""
          << "EXAMPLE 3:" << endl;
     cout << setfill('*') << setw(20) << "" << endl;

     int a = 7, b = 3;
     cout << "a / b: " << (float)a / (float)b << endl;
     return 0;
}