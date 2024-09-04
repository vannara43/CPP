#include "ElectricCar.h"
#include "Engine.h"

ElectricCar::ElectricCar() : Car(), batteryLife(0), engine(engine) {};

ElectricCar::ElectricCar(string name, int established, int year, int maxSpeed, int mileage, int mpg, int batteryLife, Engine engine)
    : Car(name, established, year, maxSpeed, mileage, mpg), batteryLife(batteryLife), engine(engine) {};

// Mutator
void ElectricCar::setBatteryLife(int batteryLife)
{
    this->batteryLife = batteryLife;
}
// Mutator
void ElectricCar::setEnginePart(int enginePart)
{
    this->engine.setEnginePart(enginePart);
}

// Mutator
void ElectricCar::setEngineSize(int engineSize)
{
    this->engine.setEngineSize(engineSize);
}

// Mutator
void ElectricCar::setEngineWeight(int engineWeight)
{
    this->engine.setEngineWeight(engineWeight);
}
// Mutator
void ElectricCar::setEngineHealth(int engineHealth)
{
    this->engine.setEngineHealth(engineHealth);
}

// Assessors: Get battery life
int ElectricCar::getBatteryLife() const
{
    return batteryLife;
}
// Assessors
int ElectricCar::getEnginePart() const
{
    return engine.getEnginePart();
}
// Assessors
int ElectricCar::getEngineSize() const
{
    return engine.getEngineSize();
}
// Assessors
int ElectricCar::getEngineWeight() const
{
    return engine.getEngineWeight();
}
// Assessors
int ElectricCar::getEngineHealth() const
{
    return engine.getEngineHealth();
}

void ElectricCar::show()
{
    cout << "INFORMATION" << endl;
    cout << "************************************" << endl;
    cout << "Name of car: " << getName() << endl;
    cout << "What year is this car created: " << getEstablished() << endl;
    cout << "Year : " << getYear() << endl;
    cout << "Max Speed: " << getMaxSpeed() << endl;
    cout << "Mileage: " << getMileage() << endl;
    cout << "Miles per gallon: " << getMpg() << endl;
    cout << "Battery Life: " << getBatteryLife() << endl;
    cout << "Engine: " << endl;
    cout << "\t- Part#: " << engine.getEnginePart() << endl;
    cout << "\t- Size: " << engine.getEngineSize() << endl;
    cout << "\t- Weight: " << engine.getEngineWeight() << endl;
    cout << "\t- Health: " << engine.getEngineHealth() << endl;
    cout << "************************************" << endl;
}

void ElectricCar::speak()
{
    cout << "I'm an electric car. Zap! Zap!" << endl;
}