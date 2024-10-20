/* Copyright © 2023 by venkys.io   Visit https://venkys.io for more information */
// C++ program to implement Simple Sort
// Stable: Yes
// Inplace: Yes
// Adaptive: Yes
// Space complexity: O(1)
// Time Complexity:
// | Algorithm | Best Case | Average Case | Worst Case |
// | --------- | --------- | ------------ | ---------- |
// | SimpleSort| O(n^2)    | O(n^2)       | O(n^2)     |

#include <iostream>
// function to swap two numbers using a temporary variable
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// function for sorting numbers
void SimpleSort(int arr[], int n)
{
    // traverse through all array elements using index i   
    for (int i = 0; i < n; i++)
    {
        // traverse through all array elements using index j   
        for (int j = 0; j < n; j++)
        {
            // if the element at index i is less than the element at index j, then swap the elements   
            if (arr[i] < arr[j])
            {
                // calling the swap function   
                swap(arr, i, j);
            }
        }
    }

    // print the sorted array   
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
// main function
int main()
{
    int n = 7;
    int arr[] = {2, 24, 12, 96, 456, 899, 34};
    // array intialization   
    SimpleSort(arr, n);

    // calling sort function   
    return 0;
}
