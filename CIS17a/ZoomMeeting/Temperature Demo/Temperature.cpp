/*
 * File:   Temperature.cpp
 * Author: pconrad
 *
 * Created on April 17, 2024, 1:12 PM
 */

#include "Temperature.h"

Temperature::Temperature()
{
    this->temperature_value = 0.0;
    this->temperature_unit = 'C';
}

Temperature::Temperature(double value, char unit)
{
    if (this->setTemperatureUnit(unit) == true)
    {
        // attempt to set the temperature value
        if (this->setTemperatureValue(value) == false)
        {
            cout << "ERROR: " << value << "°" << this->getTemperatureUnit();
            cout << " is not a valid value (setting to default value of 0." << endl;
        }
    }
    else
    {
        cout << "ERROR: " << unit << " is not a valid unit (setting to default 'C')" << endl;
    }
}

Temperature::Temperature(const Temperature &orig)
{
    char unit = orig.getTemperatureUnit();
    double value = orig.getTemperatureValue();

    if (this->setTemperatureUnit(unit) == true)
    {
        // attempt to set the temperature value
        if (this->setTemperatureValue(value) == false)
        {
            cout << "ERROR: " << value << "°" << this->getTemperatureUnit();
            cout << " is not a valid value (setting to default value of 0." << endl;
        }
    }
    else
    {
        cout << "ERROR: " << unit << " is not a valid unit (setting to default 'C')" << endl;
    }
}

Temperature::~Temperature()
{
}

bool Temperature::setTemperatureUnit(char temperature_unit)
{
    bool success = true;

    switch (temperature_unit)
    {
    case 'K':
    case 'k':
        this->temperature_unit = 'K';
        break;

    case 'F':
    case 'f':
        this->temperature_unit = 'F';
        break;

    case 'C':
    case 'c':
        this->temperature_unit = 'C';
        break;

    default:
        this->temperature_unit = 'C';
        success = false;
    }
    return success;
}

char Temperature::getTemperatureUnit() const
{
    return temperature_unit;
}

bool Temperature::setTemperatureValue(double temperature_value)
{
    bool success = false;

    switch (this->getTemperatureUnit())
    {
    case 'K':
        if (temperature_value >= 0)
            success = true;
        break;

    case 'F':
        if (temperature_value >= -459.634)
            success = true;
        break;

    case 'C':
        if (temperature_value >= -273.13)
            success = true;
    }

    if (success == true)
        this->temperature_value = temperature_value;
    else
        this->temperature_value = 0.0;
}

double Temperature::getTemperatureValue() const
{
    return temperature_value;
}

ostream &operator<<(ostream &o, const Temperature &t)
{
    o << t.getTemperatureValue() << "°" << t.getTemperatureUnit();
    return o;
}
