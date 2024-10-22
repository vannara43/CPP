/* Copyright © 2023 by venkys.io
Visit https://venkys.io for more information */
// C++ program to implement Merge Sort
// Stable: Yes
// Inplace: No
// Adaptive: No
// Space complexity: O(n)
// Time Complexity:
// | Algorithm | Best Case | Average Case | Worst Case |
// | --------- | --------- | ------------ | ---------- |
// | MergeSort | O(n log n)| O(n log n)   | O(n log n) |
#include <iostream>

// Function Prototype
void merge(int arr[], int l, int m, int r);
void mergesort(int arr[], int l, int r);

// main function
int main()
{
    int n = 7;
    int arr[] = {2, 24, 12, 96, 456, 899, 34};
    // array intialization
    mergesort(arr, 0, n - 1);
    // calling mergesort function
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
} // Sample Input: 2 24 12 96 456 899 34  // Sample Output: 2 12 24 34 96 456 899

// merge function declaration
void merge(int arr[], int l, int m, int r)
{
    // size of the two subarrays
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1]; // new left array for storing sort values
    int right[n2];
    // new right array for storing sort values
    // copying the values to the new arrays
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    // copying the values to the new arrays
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0;
    int k = l;

    // merging the two arrays
    while (i < n1 && j < n2)
    {
        // comparing the values of left and right array
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        // if the value of right array is less than the left array
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // copying the remaining elements of left array
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // copying the remaining elements of right array
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// merge sort implementation
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // sorting the mid value
        mergesort(arr, l, m);
        // mergesort on left part
        mergesort(arr, m + 1, r);
        // mergesort on right part
        merge(arr, l, m, r);
        // combining the sorted atomic parts
    }
}