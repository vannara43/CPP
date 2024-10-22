#include <iostream>
#include <string>
#include <stack>

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
    stack<Person> personStack; // This is the stack

    // Push the three person objects onto the stack
    cout << "Pushing " << p1.getName() << endl;
    personStack.push(p1);
    cout << "Pushing " << p2.getName() << endl;
    personStack.push(p2);
    cout << "Pushing " << p3.getName() << endl;
    personStack.push(p3);

    cout << endl;

    // Pop the objects off the stack.
    while (!personStack.empty())
    {
        cout << "Popped " << personStack.top().getName() << endl;
        personStack.pop();
        // or
        // Person myPerson = personStack.top();
        // cout << "Popped " << myPerson.getName() << endl;
        // personStack.pop();
    }

    return 0;
}