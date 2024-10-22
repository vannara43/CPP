#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> &arr);

int main()
{
    vector<int> arr = {2, 6, 1, 3, 4, 5, 9};
    int n = arr.size();
    selectionSort(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

vector<int> selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    return arr;
}