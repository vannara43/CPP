#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    // define a set of strings
    set<string> team{"Joe", "Karen", "Lisa", "Jackie"};

    // Insert two new strings into the set
    team.insert("Will");
    team.insert("Alice");
    team.insert("Joe");

    // Take a look at the elements
    for (string e : team)
        cout << e << endl;

    return 0;
}