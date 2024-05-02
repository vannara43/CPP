// Vannara Thong CSC5 Chapter 4, P. 224, #19
//
/**************************************************************
 *
 * THE SPEED OF SOUND IN GAS
 * ____________________________________________________________
 * This program computes the miles a car can travel on one
 * gallon on gas.
 *
 *
 * Computation is based on the formula:
 * MilesPerGallon = Number of Gallons / Max Mileage on Full Tank
 * ____________________________________________________________
 * INPUT
 * gallonsCanHold		: Total Gallon in car
 * milesDrivenFullTank  : Total Miles on Full tank of Gas
 *
 *
 * OUTPUT
 * gasMilagePerGallon   : Get miles per gallon
 *
 **************************************************************/

#include <iostream>

using namespace std;

/*  The Speed of Sound in Gases

    When sound travels through a gas, its speed depends primarily on the density of the
    medium. The less dense the medium, the faster the speed will be. The following table
    shows the approximate speed of sound at 0 degrees centigrade, measured in meters
    per second, when traveling through carbon dioxide, air, helium, and hydrogen.

    Write a program that displays a menu allowing the user to select one of these four
    gases. After a selection has been made, the user should enter the number of seconds it
    took for the sound to travel in this medium from its source to the location at which it
    was detected. The program should then report how far away (in meters) the source of
    the sound was from the detection location.

    Input Validation: Check that the user has selected one of the available menu choices.
    Do not accept times less than 0 seconds or more than 30 seconds.
*/

int main()
{

    const int AIR_FEET_PER_SECOND = 1100;
    const int WATER_FEET_PER_SECOND = 4900;
    const int STEEL_FEET_PER_SECOND = 16400;
    const int MINIMUM_DISTANCE = 1100;
    return 0;
}