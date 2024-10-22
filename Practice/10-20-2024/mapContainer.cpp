#include <iostream>
#include <map>

using namespace std;

int main()
{
    // Create a map containing employee IDs and names
    map<int, string> employees;
    employees[101] = "Chris Jones";
    employees[102] = "Jessica Smith";
    employees[103] = "Amanda Stevens";
    employees[104] = "Will Osburn";

    // Create an iterator
    map<int, string>::iterator iter;

    // Use the iterator to display each element in the map
    for (iter = employees.begin(); iter != employees.end(); ++iter)
    {
        cout << "Employee ID: " << iter->first << "\tName: " << iter->second << endl;
    }
    return 0;
}
