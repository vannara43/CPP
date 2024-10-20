/* Copyright © 2023 by venkys.io  Visit https://venkys.io for more information */
// C++ program to demonstrate Selection Sort
// Stable: No
// Adaptive: No
// Inplace: Yes
// Space complexity: O(1)
// Time Complexity:
//| Algorithm | Best Case | Average Case | Worst Case |  //| --------- | --------- | ------------ | ---------- |  //| Selection | O(n^2)   | O(n^2)       | O(n^2)     |
#include <iostream>
#include <bit>
using namespace std;

// function to swap numbers
void swap(int array[], int i, int j);
void selectionSort(int array[], int n);
void selectionSort(int array[], int n);

int main()
{
    cout << endl;
    int array[] = {1, 2, 53, 12, 45, 11, 56}; // array initialization
    int n = 7;
    selectionSort(array, n); // calling the sort function
    return 0;
} // Sample Input: 1 2 53 12 45 11 56  // Sample Output: 1 2 11 12 45 53 56

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
// function to find the minimum element
int findmin(int array[], int i, int n)
{
    int m = i;

    // loop to find the minimum element
    for (int j = i + 1; j < n; j++)
    // start the loop from i+1
    {
        // if the element at index j is less than the element at index m, then update m
        if (array[m] > array[j])
        {
            m = j;
        }
    }
    return m;
}
// function for sorting numbers
void selectionSort(int array[], int n)
{
    // loop to traverse through all array elements
    for (int i = 0; i < n; i++)
    {

        // calling the findmin function to find the minimum element
        int j = findmin(array, i, n);
        swap(array, i, j);
        // swap the min element with the current element
    }

    // print the sorted array
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}