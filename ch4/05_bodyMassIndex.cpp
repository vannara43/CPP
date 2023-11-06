#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /*
    Write a program that calculates and displays a person's body mass index (BMI). The BMI is often used to determine whether a person with a sedentary lifestyle is overweight or underweight for his or her height. A person s BMI is calculated with the following formula:

    BMI = weight × 703 / height2

    where weight is measured in pounds and height is measured in inches. The program should display a message indicating whether the person has optimal weight, is underweight, or is overweight. A sedentary person s weight is considered to be optimal if his or her BMI is between 18.5 and 25. If the BMI is less than 18.5, the person is considered to be underweight. If the BMI value is greater than 25, the person is considered to be overweight.
    */

    int weight;  // measured in pound
    int weight2; // measured in pound
    int height;  // measured in inches
    int height2; // measured in inches
    int BMI;

    cout << "Enter a weight(lb) for person 1: ";
    cin >> weight;
    cout << "Enter a height(Inches) for person 1: ";
    cin >> height;
    cout << "Enter a weight(lb) for person 2: ";
    cin >> weight2;
    cout << "Enter a height(Inches) for person 2: ";
    cin >> height2;

    BMI = weight * (703 / pow(height2, 2));

    if (BMI >= 18.5 & BMI <= 25)
    {
        cout << "Person1 weight: " << weight << "lb" << endl;
        cout << "Person1 height: " << height << "Inches" << endl;
        cout << "BMI: " << BMI << endl;
        cout << "Person weight is optimal.";
    }
    else if (BMI > 18.5)
    {
        cout << "Person1 weight: " << weight << "lb" << endl;
        cout << "Person1 height: " << height << "Inches" << endl;
        cout << "BMI: " << BMI << endl;
        cout << "Person is underweight.";
    }
    else if (BMI < 25)
    {
        cout << "Person1 weight: " << weight << "lb" << endl;
        cout << "Person1 height: " << height << "Inches" << endl;
        cout << "BMI: " << BMI << endl;
        cout << "Person is overweight." << endl;
    }

    return 0;
}