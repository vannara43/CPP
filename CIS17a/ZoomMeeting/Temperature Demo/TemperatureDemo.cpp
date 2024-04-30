
/* 
 * File:   TemperatureDemo.cpp
 * Author: pconrad
 *
 * Created on April 17, 2024, 1:08 PM
 */

#include <iostream>
#include "Temperature.h"
using namespace std;


int main(int argc, char** argv) {

    Temperature value_1;
    Temperature value_2 = Temperature(72, 'F');
    
    cout << "value_1 is " << value_1 << endl;
    cout << "value_2 is " << value_2 << endl;
    
    return 0;
}

