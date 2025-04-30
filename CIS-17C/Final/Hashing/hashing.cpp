#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int charToKeypad(char letter);
int hashFunction(const string &initials);
string generateRandomInitials();
void insertIntoHashTable(vector<list<string>> &table, const string &initials);
void analyzeHashTable(const vector<list<string>> &table);
int maxCollisions(const vector<list<string>> &table);

int main()
{
    srand(time(0)); // Seed for random number generation

    // Initialize hash table
    vector<list<string>> hashTable(512);

    // Generate 512 random initials and populate the hash table
    for (int i = 0; i < 512; ++i)
    {
        string initials = generateRandomInitials();
        insertIntoHashTable(hashTable, initials);
    }

    // Analyze and display hash table statistics
    analyzeHashTable(hashTable);
    cout << "Maximum number of collisions in a single bucket: " << maxCollisions(hashTable) << endl;

    return 0;
}

int charToKeypad(char letter)
{
    switch (letter)
    {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return 9;
    default:
        return -1; // error
    }
}

int hashFunction(const string &initials)
{
    int hashValue = 0;
    for (char c : initials)
    {
        hashValue = hashValue * 10 + charToKeypad(c);
    }
    return hashValue % 512; // Map to 512 buckets
}

string generateRandomInitials()
{
    string initials = "";
    for (int i = 0; i < 3; ++i)
    {
        initials += 'A' + rand() % 26; // Random uppercase letter
    }
    return initials;
}

void insertIntoHashTable(vector<list<string>> &table, const string &initials)
{
    int index = hashFunction(initials);
    table[index].push_back(initials);
}

void analyzeHashTable(const vector<list<string>> &table)
{
    map<int, int> bucketCounts; // Key: number of elements, Value: bucket count
    for (const auto &bucket : table)
    {
        int size = bucket.size();
        bucketCounts[size]++;
    }

    for (const auto &pair : bucketCounts)
    {
        cout << pair.second << " buckets have " << pair.first << " elements." << endl;
    }
}

int maxCollisions(const vector<list<string>> &table)
{
    int maxSize = 0;
    for (const auto &bucket : table)
    {
        maxSize = max(maxSize, static_cast<int>(bucket.size()));
    }
    return maxSize;
}