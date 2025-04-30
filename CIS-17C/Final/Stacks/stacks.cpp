#include <iostream>
#include <stack>
#include <iomanip>
#include <cmath>
using namespace std;

// Global stacks for tracking calls
stack<float> sinhStack;
stack<float> coshStack;

// Function declarations (from document)
float g(float angR);
float h(float angR);

// Function definitions
float h(float angR)
{
    sinhStack.push(angR); // Track sinh call
    float tol = 1e-6;
    if (angR > -tol && angR < tol)
        return angR + angR * angR * angR / 6;
    return 2 * h(angR / 2) * g(angR / 2);
}

float g(float angR)
{
    coshStack.push(angR); // Track cosh call
    float tol = 1e-6;
    if (angR > -tol && angR < tol)
        return 1 + angR * angR / 2;
    float b = h(angR / 2);
    return 1 + 2 * b * b;
}

int main()
{
    cout << setw(10) << "Angle" << setw(15) << "sinh Calls" << setw(15) << "cosh Calls" << endl;
    cout << string(40, '-') << endl;

    for (float angle = -1.0; angle <= 1.0; angle += 0.1)
    {
        // Clear the stacks before each calculation
        while (!sinhStack.empty())
            sinhStack.pop();
        while (!coshStack.empty())
            coshStack.pop();

        // Compute sinh
        h(angle);

        // Output the results
        cout << setw(10) << angle
             << setw(15) << sinhStack.size()
             << setw(15) << coshStack.size() << endl;
    }

    return 0;
}
