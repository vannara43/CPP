// This program demonstrates a constructor.
#include <iostream>

using namespace std;

class Car
{
public:
    int door1;
    int door2;
    int door3;
    int door4;
    Car(int door1);
    Car(int door1, int door2);
    Car(int door1, int door2, int door3);
    Car(int door1, int door2, int door3, int door4);
};

Car::Car(int door1)
{
    cout << "\nThis car has 1 door." << endl;
}

Car::Car(int door1, int door2, int door3)
{
    cout << "\nThis car has 3 door. Weird car." << endl;
}

Car::Car(int door1, int door2, int door3, int door4)
{
    cout << "\nThis car has 4 door. This is a sudan." << endl;
}

main()
{
    Car d(1, 1, 1, 1);
    return 0;
}