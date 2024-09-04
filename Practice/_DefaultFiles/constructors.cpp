// This program demonstrates a constructor.
#include <iostream>

using namespace std;

class Demo
{
public:
    Demo();
};

Demo::Demo()
{
    cout << "\nThis is the constructor for Demo." << endl;
}

main()
{
    Demo d;
    cout << "Demo constructor is executed before this cout message." << endl;
    return 0;
}