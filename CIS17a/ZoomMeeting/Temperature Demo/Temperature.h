/*
 * File:   Temperature.h
 * Author: pconrad
 *
 * Created on April 17, 2024, 1:12 PM
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
using namespace std;

// Constructor: Public member overview
class Temperature
{
public:
    Temperature();
    Temperature(double value, char unit);
    Temperature(const Temperature &orig); // destructure
    virtual ~Temperature();

    bool setTemperatureUnit(char temperature_unit);
    char getTemperatureUnit() const;

    bool setTemperatureValue(double temperature_value);
    double getTemperatureValue() const;

    friend ostream &operator<<(ostream &o, const Temperature &t); // overloaded stream insertion operator

private:
    double temperature_value;
    char temperature_unit;
};

#endif /* TEMPERATURE_H */
