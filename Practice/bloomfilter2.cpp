#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int BIT_VECTOR_SIZE = 100;
const int NUM_HASH_FUNCTIONS = 3;

// RS hash function
unsigned int RSHash(const char *str, unsigned int len)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    for (unsigned int i = 0; i < len; i++)
    {
        hash = hash * a + str[i];
        a = a * b;
    }

    return hash % BIT_VECTOR_SIZE;
}

// JS hash function
unsigned int JSHash(const char *str, unsigned int len)
{
    unsigned int hash = 1315423911;

    for (unsigned int i = 0; i < len; i++)
    {
        hash ^= ((hash << 5) + str[i] + (hash >> 2));
    }

    return hash % BIT_VECTOR_SIZE;
}

// PJW hash function
unsigned int PJWHash(const char *str, unsigned int len)
{
    const unsigned int BitsInUnsignedInt = sizeof(unsigned int) * 8;
    const unsigned int ThreeQuarters = (BitsInUnsignedInt * 3) / 4;
    const unsigned int OneEighth = BitsInUnsignedInt / 8;
    const unsigned int HighBits = 0xFFFFFFFF << (BitsInUnsignedInt - OneEighth);

    unsigned int hash = 0;
    unsigned int test = 0;

    for (unsigned int i = 0; i < len; i++)
    {
        hash = (hash << OneEighth) + str[i];

        if ((test = hash & HighBits) != 0)
        {
            hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
        }
    }

    return hash % BIT_VECTOR_SIZE;
}

// Add a name to the filter
void addToFilter(const char *name, vector<bool> &bitVector)
{
    unsigned int len = strlen(name);

    bitVector[RSHash(name, len)] = true;
    bitVector[JSHash(name, len)] = true;
    bitVector[PJWHash(name, len)] = true;
}

// Check if a name is in the filter
bool probablyInFilter(const char *name, const vector<bool> &bitVector)
{
    unsigned int len = strlen(name);

    return bitVector[RSHash(name, len)] &&
           bitVector[JSHash(name, len)] &&
           bitVector[PJWHash(name, len)];
}

int main()
{
    // Initialize bit vector
    vector<bool> bitVector(BIT_VECTOR_SIZE, false);

    // Add names to the filter
    addToFilter("Alice", bitVector);
    addToFilter("Bob", bitVector);
    addToFilter("Charlie", bitVector);
    addToFilter("David", bitVector);

    // Test names for presence in the filter
    cout << "Alice: " << probablyInFilter("Alice", bitVector) << endl;
    cout << "Bob: " << probablyInFilter("Bob", bitVector) << endl;
    cout << "Eve: " << probablyInFilter("Eve", bitVector) << endl;
    cout << "David: " << probablyInFilter("David", bitVector) << endl;

    // Simulate random names and calculate false positives
    srand(time(0));
    int numNames = 1000;
    int falsePositives = 0;

    for (int i = 0; i < numNames; i++)
    {
        // Generate random 5-character names
        char randomName[6];
        for (int j = 0; j < 5; j++)
        {
            randomName[j] = 'a' + rand() % 26;
        }
        randomName[5] = '\0';

        // Check for false positives
        if (probablyInFilter(randomName, bitVector) &&
            strcmp(randomName, "Alice") != 0 &&
            strcmp(randomName, "Bob") != 0 &&
            strcmp(randomName, "Charlie") != 0 &&
            strcmp(randomName, "David") != 0)
        {
            falsePositives++;
        }
    }

    // Calculate probabilities
    double probFalsePositives = static_cast<double>(falsePositives) / numNames;
    double probFalsePositiveTheoretical =
        pow(1 - exp(-NUM_HASH_FUNCTIONS * static_cast<double>(numNames) / BIT_VECTOR_SIZE), NUM_HASH_FUNCTIONS);

    cout << endl;
    cout << "False Positives results below" << endl;
    cout << "Simulated probability: " << probFalsePositives << endl;
    cout << "Theoretical probability: " << probFalsePositiveTheoretical << endl;

    return 0;
}
