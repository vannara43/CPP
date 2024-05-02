#include <iostream>
#include <iomanip>
using namespace std;

float sumFunction(float a, float b)
{
    float sum = a + b;
    return sum;
}
float sumFunction2(float c)
{
    float sum = c + 100;
    return sum;
}

int main()
{
    float a, b, c;
    cout << "Enter a value: " << endl;
    cin >> a;
    cout << "Enter b value: " << endl;
    cin >> b;

    cout << "value a : " << a << "|| value b: " << b << endl;
    c = sumFunction(a, b);
    if (c > 100)
    {
        cout << "C is greater than 100 \n\nFunction2 is running now";
        cout << "\n\nResult is now: " << sumFunction2(c);
    }
    else
    {
        cout << "\nc is less than 100\n\nResult is " << a + b;
    }

    cin.ignore();
    cin.get();
    return 0;
    // vscode is gay
}