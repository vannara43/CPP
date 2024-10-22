#include <iostream>
#include <map>

using namespace std;

int main()
{
    int searchID; // ID to search for

    // Create a map containing employee IDs and names
    map<int, string> employees{
        {101, "Chris Jones"}, {102, "Jessica Smith"}, {103, "Amanda Stevens"}, {104, "Will Osburn"}};

    // Get an ID to search for
    cout << "Enter an ID to search for: ";
    cin >> searchID;

    // Search for an ID
    auto it = employees.find(searchID);

    // Display the results
    if (it != employees.end())
        cout << "ID: " << it->first << "\tName: " << it->second << endl;
    else
        cout << "That ID is not found.\n";
    return 0;
}
