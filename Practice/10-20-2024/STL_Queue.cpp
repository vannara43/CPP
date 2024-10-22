#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Person
{
private:
    string name;

public:
    // Default Constructor
    Person()
    {
        name = "";
    }

    // Overloaded Constructor
    Person(string n)
    {
        name = n;
    }

    // Get Name Function()
    string getName()
    {
        return name;
    }
};

int main()
{
    // Create 3 person object
    Person p1{"Kathryn"};
    Person p2{"Chris"};
    Person p3{"Joanne"};

    // Create a stack to hold person object
    queue<Person> personQueue; // This is the stack

    // Push the three person objects onto the stack
    cout << "Pushing " << p1.getName() << endl;
    personQueue.push(p1);
    cout << "Pushing " << p2.getName() << endl;
    personQueue.push(p2);
    cout << "Pushing " << p3.getName() << endl;
    personQueue.push(p3);

    cout << endl;

    // Pop the objects off the stack.
    while (!personQueue.empty())
    {
        cout << "Popped " << personQueue.front().getName() << endl;
        personQueue.pop();
        // or
        // Person myPerson = personQueue.front();
        // cout << "Popped " << myPerson.getName() << endl;
        // personQueue.pop();
    }

    return 0;
}