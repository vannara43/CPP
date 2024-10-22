#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string search;

    // define a set of strings
    set<string> team{"Joe", "Karen", "Lisa", "Jackie"};

    // Insert two new strings into the set
    team.insert("Will");
    team.insert("Alice");
    team.insert("Joe");

    // Get a string to search for
    cout << "Who do you want to search for? ";
    getline(cin, search);

    // Search for the string
    if (team.count(search))
    {
        cout << "Yes, that name was found in the set.\n";
    }
    else
    {
        cout << "No, that string was not found.\n";
    }

    return 0;
}