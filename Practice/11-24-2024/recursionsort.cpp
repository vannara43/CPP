#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void qsort(int arr[], int left, int right);
void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);
void shellsort(int arr[], int n);

int main()
{
    srand(static_cast<unsigned>(time(0)));

    const int n = 2000000;

    int *arr = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    int *arr4 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 2000000;
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }

    clock_t start = clock();
    qsort(arr, 0, n - 1);
    clock_t end = clock();
    cout << "Quick Sort took " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    mergesort(arr2, 0, n - 1);
    end = clock();
    cout << "Merge Sort took " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    heapsort(arr3, n);
    end = clock();
    cout << "Heap Sort took " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    shellsort(arr4, n);
    end = clock();
    cout << "Shell Sort took " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}

void qsort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; ++j)
        {
            if (arr[j] < pivot)
            {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);

        int partitionIndex = i + 1;
        qsort(arr, left, partitionIndex - 1);
        qsort(arr, partitionIndex + 1, right);
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void shellsort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
