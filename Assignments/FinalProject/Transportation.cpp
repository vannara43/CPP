#include <iostream>
#include <string>

using namespace std;

// Base Class
class Transportation
{
private:
    string name;
    int established;

public:
    Transportation(string name, int established);
    string getName()
    {
        this->name = name;
        return name;
    }

    int getEstablished()
    {
        this->established = established;
        return established;
    }
    virtual void show()
    {
        cout << "Transportation Name : " << getName() << endl;
        cout << "Established Year : " << getEstablished() << endl;
    }

    virtual void sound()
    {
        cout << "This is a base class" << endl;
    }
};

Transportation::Transportation(string name, int established)
{
    this->name = name;
    this->established = established;
}

/* CAR CLASS */
// Sub-class
class Car : public Transportation
{
private:
    int year;
    int maxSpeed;
    int mileage;
    int mpg;

public:
    int getYear() const;
    int getMaxSpeed() const;
    int getMileage() const;
    int getMpg() const;
    Car(string name, int established, int year, int maxSpeed, int mileage, int mpg) : Transportation(name, established), year(year), maxSpeed(maxSpeed), mileage(mileage), mpg(mpg){};

    void show()
    {
        cout << "Name : " << getName() << endl;
        cout << "Established Year : " << getEstablished() << endl;
        cout << "Year : " << year << endl;
        cout << "Max Speed: " << maxSpeed << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "Miles per gallon: " << mpg << endl;
    }

    void sound()
    {
        cout << "The car makes a vroom sound" << endl;
    }
};

// getYear returns the value in the private member year.
int Car::getYear() const
{
    return this->year;
}

// getMaxSpeed returns the value in the private member maxSpeed.
int Car::getMaxSpeed() const
{
    return maxSpeed;
}

// getMileage returns the value in the private member mileage.
int Car::getMileage() const
{
    return mileage;
}

// getMpg returns the value in the private member mpg.
int Car::getMpg() const
{
    return mpg;
}

/* END OF CAR CLASS */

// Sub-class
class Boat : public Transportation
{
private:
    int year;
    int maxSpeed;
    int mileage;
    int mpg;

public:
    Boat(string name, int established, int year, int maxSpeed, int mileage, int mpg) : Transportation(name, established), year(year), maxSpeed(maxSpeed){};

    void show()
    {
        cout << "Name : " << getName() << endl;
        cout << "Established : " << getYear() << endl;
        cout << "Year : " << getYear() << endl;
        cout << "Max Speed: " << getMaxSpeed() << endl;
        cout << "Mileage: " << getYear() << endl;
        cout << "Miles per gallon: " << getMaxSpeed() << endl;
    }

    void sound()
    {
        cout << "The boat just splashed water" << endl;
    }

    int getYear()
    {
        return year;
    }

    int getMaxSpeed()
    {
        return maxSpeed;
    }
};

// Composite Class: Engine
class Engine
{
private:
    int enginePart;

public:
    Engine(int enginePart) : enginePart(enginePart){};

    int getEnginePart()
    {
        return this->enginePart;
    }
};

// Derive class of Sub-class Car
class ElectricCar : public Car
{
private:
    int batteryLife;
    Engine enginePart;

public:
    ElectricCar(string name, int established, int year, int maxSpeed, int mileage, int mpg, int batteryLife, Engine enginePart) : Car(name, established, year, maxSpeed, mileage, mpg), batteryLife(batteryLife), enginePart(enginePart){};

    void show()
    {
        cout << "Name : " << getName() << endl;
        cout << "Established Year : " << getEstablished() << endl;
        cout << "Year : " << getYear() << endl;
        cout << "Max Speed: " << getMaxSpeed() << endl;
        cout << "Mileage: " << getMileage() << endl;
        cout << "Miles per gallon: " << getMpg() << endl;
        cout << "Battery Life: " << getBatteryLife() << endl;
        cout << "Engine Part#: " << getEngineType() << endl;
    }

    void sound()
    {
        cout << "The electric car makes a soft vroom sound" << endl;
    }
    int getBatteryLife()
    {
        return batteryLife;
    }

    int getEngineType()
    {
        return enginePart.getEnginePart();
    }
};

int main()
{
    Transportation t("Welcome to our Transportation Station.", 1980);
    Car c("Honda Car", 1948, 2005, 140, 56000, 45);
    Boat b("Telsa Boat", 1898, 2012, 40, 8000, 30);
    ElectricCar ec("Toyota Prius", 1997, 2019, 110, 131000, 55, 10000, 203);

    cout << endl;
    t.show();
    t.sound();
    cout << endl;
    c.show();
    c.sound();
    cout << endl;
    b.show();
    b.sound();
    cout << endl;
    ec.show();
    ec.sound();

    return 0;
}