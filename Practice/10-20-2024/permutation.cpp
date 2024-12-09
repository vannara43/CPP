#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

unsigned long long factorial(int num)
{
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result *= i;
    }
    return result;
}

unsigned long long permWithReplacement(int n, int m)
{
    unsigned long long result = 1;
    for (int i = 0; i <= m; ++i)
    {
        result *= n;
    }
    return result;
}

unsigned long long permWithoutReplacement(int n, int m)
{
    return factorial(n) / factorial(n - m);
}

unsigned long long combWithReplacement(int n, int m)
{
    return factorial(n + m - 1) / (factorial(n - 1) * factorial(m));
}

unsigned long long combWithoutReplacement(int n, int m)
{
    return factorial(n) / (factorial(n - m) * factorial(m));
}

int main()
{
    cout << "P -> Permutation (Order Matters)" << endl;
    cout << "C -> Combination (Order does not matter)" << endl;
    cout << "Rep -> with replacement" << endl;
    cout << "no Rep -> no replacement" << endl;
    cout << "N -> Number of total elements" << endl;
    cout << "M -> Number of elements to take from the total" << endl
         << endl;

    // Display headers
    cout << setw(3) << "N" << setw(5) << "M"
         << setw(25) << "P Rep"
         << setw(25) << "P no Rep"
         << setw(25) << "C Rep"
         << setw(25) << "C no Rep" << endl;

    cout << setw(3) << " " << setw(5) << " "
         << setw(25) << "(n^m)"
         << setw(25) << "(n!/(n-m)!)"
         << setw(25) << "((n+m-1)!/(n-1)!m!)"
         << setw(25) << "(n!/((n-m)!m!))" << endl;

    for (int n = 2; n <= 26; ++n)
    {
        for (int m = 0; m <= n; ++m)
        {
            cout << setw(3) << n << setw(5) << m;
            cout << setw(25) << scientific << permWithReplacement(n, m);
            cout << setw(25) << permWithoutReplacement(n, m);
            cout << setw(25) << combWithReplacement(n, m);
            cout << setw(25) << combWithoutReplacement(n, m) << endl;
        }
        cout << endl;
    }

    return 0;
}