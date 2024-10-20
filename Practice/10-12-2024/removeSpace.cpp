#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Hello World";
    string result;
    for (char c : str)
    {
        if (c != ' ')
        {
            result += c;
        }
    }

    cout << result << endl;
    return 0;
}