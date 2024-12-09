#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int BIT_VECTOR_SIZE = 100;
const int NUM_HASH_FUNCTIONS = 3;

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

unsigned int JSHash(const char *str, unsigned int len)
{
    unsigned int hash = 1315423911;
    for (unsigned int i = 0; i < len; i++)
    {
        hash ^= ((hash << 5) + str[i] + (hash >> 2));
    }
    return hash % BIT_VECTOR_SIZE;
}

unsigned int PJWHash(const char *str, unsigned int len)
{
    const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
    const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
    const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
    const unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
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

void addToFilter(const char *name, vector<bool> &bitVector)
{
    unsigned int len = strlen(name);
    unsigned int hash1 = RSHash(name, len);
    unsigned int hash2 = JSHash(name, len);
    unsigned int hash3 = PJWHash(name, len);

    bitVector[hash1] = true;
    bitVector[hash2] = true;
    bitVector[hash3] = true;
}

bool probablyInFilter(const char *name, const vector<bool> &bitVector)
{
    unsigned int len = strlen(name);
    unsigned int hash1 = RSHash(name, len);
    unsigned int hash2 = JSHash(name, len);
    unsigned int hash3 = PJWHash(name, len);

    return bitVector[hash1] && bitVector[hash2] && bitVector[hash3];
}

int main()
{
    vector<bool> bitVector(BIT_VECTOR_SIZE, false);

    addToFilter("Alice", bitVector);
    addToFilter("Bob", bitVector);
    addToFilter("Charlie", bitVector);
    addToFilter("David", bitVector);

    cout << "Alice: " << probablyInFilter("Alice", bitVector) << endl;
    cout << "Bob: " << probablyInFilter("Bob", bitVector) << endl;
    cout << "Eve: " << probablyInFilter("Eve", bitVector) << endl;
    cout << "David: " << probablyInFilter("David", bitVector) << endl;

    srand(time(0));
    int numNames = 1000;
    int falsePositives = 0;

    for (int i = 0; i < numNames; i++)
    {
        char randomName[6];
        for (int j = 0; j < 5; j++)
        {
            randomName[j] = 'a' + rand() % 26;
        }
        randomName[5] = '\0';

        if (probablyInFilter(randomName, bitVector))
        {
            if (strcmp(randomName, "Alice") != 0 &&
                strcmp(randomName, "Bob") != 0 &&
                strcmp(randomName, "Charlie") != 0 &&
                strcmp(randomName, "David") != 0)
            {
                falsePositives++;
            }
        }
    }

    double probFalsePositives = (double)falsePositives / numNames;
    cout << "Simulated probability of false positives: " << probFalsePositives << endl;

    double probFalsePositiveTheoretical = pow(1 - exp(-NUM_HASH_FUNCTIONS * (double)numNames / BIT_VECTOR_SIZE), NUM_HASH_FUNCTIONS);
    cout << "Theoretical probability of false positives: " << probFalsePositiveTheoretical << endl;

    return 0;
}