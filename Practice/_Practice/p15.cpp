// Practice 15: A Program to use While Loop
#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    cout << "while loop \n"
         << endl;
    while (x <= 20)
    {
        cout << "The value of x is : " << x << endl;
        x = x + 1;
    }
    return 0;
}
