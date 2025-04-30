#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// AVL Node structure
struct AVLNode
{
    string data;    // 3-letter initial
    AVLNode *left;  // Left child
    AVLNode *right; // Right child
    int height;     // Height of the node

    AVLNode(string val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Hashing Functions
int charToKeypad(char letter);
int hashFunction(const string &initials);
string generateRandomInitials();
void insertIntoHashTable(vector<list<string>> &table, const string &initials);
void analyzeHashTable(const vector<list<string>> &table);
int maxCollisions(const vector<list<string>> &table);

// AVL Tree Functions
int getHeight(AVLNode *node);
AVLNode *rotateRight(AVLNode *y);
AVLNode *rotateLeft(AVLNode *x);
AVLNode *insert(AVLNode *node, string data);
bool search(AVLNode *root, const string &data, int &comparisons);

int main()
{
    srand(time(0)); // Seed for random number generation

    // Initialize hash table
    vector<list<string>> hashTable(512);

    // Initialize AVL tree root
    AVLNode *root = nullptr;

    // Generate 512 random initials and populate the hash table and AVL tree
    vector<string> initials;
    for (int i = 0; i < 512; ++i)
    {
        string initial = generateRandomInitials();
        initials.push_back(initial);
        insertIntoHashTable(hashTable, initial);
        root = insert(root, initial);
    }

    // Analyze hash table
    analyzeHashTable(hashTable);
    cout << "Maximum number of collisions in a single bucket: " << maxCollisions(hashTable) << endl;

    // Choose a random initial to search
    string searchInitial = initials[rand() % initials.size()];

    // Search in hash table
    int hashComparisons = 1; // Assume constant lookup
    int hashBucket = hashFunction(searchInitial);
    for (const string &val : hashTable[hashBucket])
    {
        if (val == searchInitial)
            break;
        ++hashComparisons;
    }

    // Search in AVL tree
    int avlComparisons = 0;
    bool found = search(root, searchInitial, avlComparisons);

    // Output results
    cout << "Initial to search: " << searchInitial << endl;
    cout << "Found in hash table: Yes" << endl;
    cout << "Hash table comparisons: " << hashComparisons << endl;
    cout << "Found in AVL tree: " << (found ? "Yes" : "No") << endl;
    cout << "AVL tree comparisons: " << avlComparisons << endl;

    return 0;
}

// Hashing Functions Implementation
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
        return -1; // Error
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

// AVL Tree Functions Implementation
int getHeight(AVLNode *node)
{
    return node ? node->height : 0;
}

AVLNode *rotateRight(AVLNode *y)
{
    AVLNode *x = y->left;
    y->left = x->right;
    x->right = y;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode *rotateLeft(AVLNode *x)
{
    AVLNode *y = x->right;
    x->right = y->left;
    y->left = x;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *node, string data)
{
    if (!node)
        return new AVLNode(data);

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        return node; // Duplicates not allowed
    }

    // Update height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Balance the node
    int balance = getHeight(node->left) - getHeight(node->right);

    // Perform rotations if needed
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);
    if (balance > 1 && data > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

bool search(AVLNode *root, const string &data, int &comparisons)
{
    while (root)
    {
        ++comparisons;
        if (data == root->data)
            return true;
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}
