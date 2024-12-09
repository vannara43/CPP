#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// random string generation
string generateRandomString(int length)
{
    static const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, chars.size() - 1);

    string randomString;
    for (int i = 0; i < length; ++i)
    {
        randomString += chars[distribution(generator)];
    }
    return randomString;
}

// function for linear search
bool linearSearch(const vector<string> &arr, const string &target)
{
    for (const string &str : arr)
    {
        if (str == target)
        {
            return true;
        }
    }
    return false;
}

// function for binary search
bool binarySearch(const vector<string> &arr, const string &target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

// HashTable class
class HashTable
{
private:
    struct Node
    {
        string data;
        Node *next;
        Node(const string &data) : data(data), next(nullptr) {}
    };

    vector<Node *> table;
    int capacity;

    // hash()
    int hash(const string &key)
    {
        int hashValue = 0;
        for (char c : key)
        {
            hashValue = (hashValue * 31 + static_cast<int>(c)) % capacity;
        }
        return hashValue;
    }

public:
    // constructor for hashtable
    HashTable(int capacity) : capacity(capacity), table(capacity, nullptr) {}

    // check if the key exists
    bool contains(const string &key)
    {
        int index = hash(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->data == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // insert key
    void insert(const string &key)
    {
        int index = hash(key);
        Node *newNode = new Node(key);
        newNode->next = table[index];
        table[index] = newNode;
    }
};

int main()
{
    vector<int> sizes = {10000, 100000, 1000000};

    for (int size : sizes)
    {
        cout << "\nArray size: " << size << endl;

        // generate data
        vector<string> data(size);
        for (int i = 0; i < size; ++i)
        {
            data[i] = generateRandomString(20);
        }

        // generate search targets
        vector<string> searchTargets;
        for (int i = 0; i < 1000; ++i)
        {
            if (i % 2 == 0)
            {
                searchTargets.push_back(data[rand() % size]);
            }
            else
            {
                searchTargets.push_back(generateRandomString(20));
            }
        }

        // timing for linear search
        auto start = high_resolution_clock::now();
        for (const string &target : searchTargets)
        {
            linearSearch(data, target);
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "Linear Search time: " << duration.count() << " microseconds" << endl;

        // timing for binary search
        sort(data.begin(), data.end());
        start = high_resolution_clock::now();
        for (const string &target : searchTargets)
        {
            binarySearch(data, target);
        }
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        cout << "Binary Search time: " << duration.count() << " microseconds" << endl;

        // timing for hash table
        HashTable hashTable(size);
        for (const string &str : data)
        {
            hashTable.insert(str);
        }
        start = high_resolution_clock::now();
        for (const string &target : searchTargets)
        {
            hashTable.contains(target);
        }
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        cout << "Hash Table Search time: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
