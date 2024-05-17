#include <iostream>
#include <string>

// Base Class: Vehicle
class Vehicle
{
public:
    std::string manufacturer;
    int year;

public:
    Vehicle(std::string _manufacturer, int _year) : manufacturer(_manufacturer), year(_year) {}

    virtual void start() = 0;
    virtual void stop() = 0;
};

// Subclass of Vehicle: Car
class Car : public Vehicle
{
public:
    std::string model;
    int numDoors;
    int numSeats;
    int horsepower;

public:
    Car(std::string _manufacturer, int _year, std::string _model, int _numDoors, int _numSeats, int _horsepower) : Vehicle(_manufacturer, _year), model(_model), numDoors(_numDoors), numSeats(_numSeats), horsepower(_horsepower) {}

    void start() override
    {
        std::cout << "Starting the " << year << " " << manufacturer << " " << model << " car." << std::endl;
    }

    void stop() override
    {
        std::cout << "Stopping the " << year << " " << manufacturer << " " << model << " car." << std::endl;
    }
};

// Subclass of Vehicle: Airplane
class Airplane : public Vehicle
{
public:
    std::string model;
    int maxAltitude;
    int maxPassengers;

public:
    Airplane(std::string _manufacturer, int _year, std::string _model, int _maxAltitude, int _maxPassengers) : Vehicle(_manufacturer, _year), model(_model), maxAltitude(_maxAltitude), maxPassengers(_maxPassengers) {}

    void start() override
    {
        std::cout << "Starting the " << year << " " << manufacturer << " " << model << " airplane." << std::endl;
    }

    void stop() override
    {
        std::cout << "Stopping the " << year << " " << manufacturer << " " << model << " airplane." << std::endl;
    }
};

// Composite Class: Engine
class Engine
{
public:
    int cylinders;
    int displacement;

public:
    Engine(int _cylinders, int _displacement) : cylinders(_cylinders), displacement(_displacement) {}

    void ignite()
    {
        std::cout << "Engine ignited." << std::endl;
    }

    void shutdown()
    {
        std::cout << "Engine shutdown." << std::endl;
    }
};

// Subclass of Car: ElectricCar
class ElectricCar : public Car
{
public:
    int batteryCapacity;
    Engine electricEngine;

public:
    ElectricCar(std::string _manufacturer, int _year, std::string _model, int _numDoors, int _numSeats, int _horsepower, int _batteryCapacity, Engine _electricEngine)
        : Car(_manufacturer, _year, _model, _numDoors, _numSeats, _horsepower), batteryCapacity(_batteryCapacity), electricEngine(_electricEngine) {}

    void start() override
    {
        std::cout << "Starting the " << year << " " << manufacturer << " " << model << " electric car." << std::endl;
    }

    void stop() override
    {
        std::cout << "Stopping the " << year << " " << manufacturer << " " << model << " electric car." << std::endl;
    }
};

int main()
{
    Car honda("Honda", 2020, "Civic", 4, 5, 158);
    Airplane boeing("Boeing", 2015, "747", 35000, 416);
    Engine electricEngine(0, 0);
    ElectricCar tesla("Tesla", 2022, "Model S", 4, 5, 520, 100, electricEngine);

    honda.start();
    honda.stop();

    boeing.start();
    boeing.stop();

    tesla.start();
    tesla.stop();

    return 0;
}
