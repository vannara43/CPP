#include <iostream>

using namespace std;

int main()
{
    // Display amount of bytes char, unsigned short int, int,
    // long, float, double
    cout << "The byte size for char: " << sizeof(char) << endl;
    cout << "The byte size for unsigned short in: " << sizeof(unsigned short int) << endl;
    cout << "The byte size for int: " << sizeof(int) << endl;
    cout << "The byte size for long: " << sizeof(long) << endl;
    cout << "The byte size for float: " << sizeof(float) << endl;
    cout << "The byte size for double: " << sizeof(double) << endl;
    return 0;
}