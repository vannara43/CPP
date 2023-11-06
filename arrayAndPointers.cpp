#include <iostream>
#include <iomanip>
#include <valarray>

using namespace std;

int main()
{
    // VARIABLE DECLARATION
    size_t sizeInt = sizeof(int);
    int numberList[] = {1, 10, 2, 6, 7, 9, 2, 6, 7, 1, 6, 3, 2, 7, 1};
    valarray<int> numberList2 = {1, 10, 2, 6, 7, 9, 2, 6, 7, 1, 6, 3, 2, 7, 1};
    string textList[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k"};
    int numberLength = sizeof(numberList) / sizeof(int);
    int numberLength2 = numberList2.size();
    int numberLength3 = sizeof(numberList) / sizeInt;
    int textLength = sizeof(textList) / sizeof(string);
    int count;
    auto *p = numberList;

    // FOR LOOP
    for (count = 0; count < numberLength3; count++)
    {
        printf("Loop %d: ", count);
        cout << p[count] << endl;
    }

    // IF STATEMENT
    if (count >= numberLength)
    {
        auto p = textList; // CONVERTS POINTER TO TEXTLIST
        for (int j = 0; j < textLength; j++)
        {
            printf("Loop %d: ", j);
            cout << p[j] << endl;
        }
    }
    return 0;
}