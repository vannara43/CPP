#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

// Function to generate random data
vector<short> generateRandomData(size_t size)
{
    vector<short> data(size);
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = rand() % 65536 - 32768; // Random short integer
    }
    return data;
}

// Selection Sort to find top p elements
vector<short> selectionSortTopP(const vector<short> &data, size_t p)
{
    vector<short> result = data; // Copy original data
    size_t n = result.size();

    for (size_t i = 0; i < p; ++i)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (result[j] > result[minIndex])
            { // Descending order
                minIndex = j;
            }
        }
        swap(result[i], result[minIndex]);
    }

    return vector<short>(result.begin(), result.begin() + p);
}

// Merge Sort Helper
void merge(vector<short> &arr, int left, int mid, int right)
{
    vector<short> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        { // Descending order
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; ++i)
    {
        arr[i] = temp[i - left];
    }
}

// Merge Sort Main
void mergeSort(vector<short> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Get top p elements using Merge Sort
vector<short> mergeSortTopP(vector<short> data, size_t p)
{
    mergeSort(data, 0, data.size() - 1); // Sort entire array
    return vector<short>(data.begin(), data.begin() + p);
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed random generator

    // Generate data
    const size_t dataSize = 100000;
    const size_t p = 8; // Number of top elements
    vector<short> data = generateRandomData(dataSize);

    // Measure Selection Sort time
    auto start = chrono::high_resolution_clock::now();
    vector<short> topPSelection = selectionSortTopP(data, p);
    auto end = chrono::high_resolution_clock::now();
    auto selectionDuration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Measure Merge Sort time
    start = chrono::high_resolution_clock::now();
    vector<short> topPMerge = mergeSortTopP(data, p);
    end = chrono::high_resolution_clock::now();
    auto mergeDuration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    // Display Results
    cout << "Top " << p << " elements (Selection Sort): ";
    for (short val : topPSelection)
        cout << val << " ";
    cout << endl;

    cout << "Top " << p << " elements (Merge Sort): ";
    for (short val : topPMerge)
        cout << val << " ";
    cout << endl;

    cout << "Selection Sort Time: " << selectionDuration << " ms" << endl;
    cout << "Merge Sort Time: " << mergeDuration << " ms" << endl;

    return 0;
}
