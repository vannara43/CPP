#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // use a lambda expression to create a function object
    auto isEven = [](int x)
    { return x % 2 == 0; };

    // get the number of elements that is even
    int evenNums = count_if(v.begin(), v.end(), isEven);

    // Display the results
    cout << "The vector contains " << evenNums << " even numbers.\n";

    return 0;
}