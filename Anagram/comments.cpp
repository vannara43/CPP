// Include iostream library for input and output operations
#include <iostream>
// Include fstream library to handle file input and output
#include <fstream>
// Include cstdlib library for random functions
#include <cstdlib>
// Include ctime library to seed random generator with the current time
#include <ctime>

// Use the standard namespace
using namespace std;

// Function to load words from a file into a fixed-size array
int loadWords(const string &filename, string words[], int maxWords)
{
    // Open the file with the provided filename
    ifstream file(filename);
    // Initialize a counter to keep track of the number of words loaded
    int count = 0;

    // Read each word from the file and store it in the array, up to the maximum word limit (maxWords)
    while (file >> words[count] && count < maxWords)
    {
        // Increment the counter for each word loaded
        count++;
    }
    // Return the actual number of words successfully loaded from the file
    return count;
}

int main()
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Display introductory message and game instructions
    cout << "Hello, welcome to my Anagram game.\n";
    cout << "You will be given a word and you have to find \nall the possible anagrams of the word.\n";
    cout << "Choose an option from the menu\n";
    cout << "1. Play the game\n";
    cout << "2. Exit the game\n";

    // Declare a variable to store the user's menu choice
    int option;
    // Read the user's input
    cin >> option;

    // Check if the user chose to play the game
    if (option == 1)
    {
        // Define the maximum number of words the array can hold
        const int maxWords = 100;
        // Declare a fixed-size array to store words from the file
        string words[maxWords];
        // Load words from the file into the array
        int wordCount = loadWords("dictionary.txt", words, maxWords);

        // Check if any words were loaded successfully from the file
        if (wordCount == 0)
        {
            // Inform the user of an error if no words are loaded and exit
            cout << "Error: No words loaded from the dictionary file.\n";
            return 1;
        }

        // Select a random word from the loaded words array
        string word = words[rand() % wordCount];

        // Optional: Uncomment the line below to display the original word for reference
        // cout << "The word to unscramble is: " << word << "\n";

        // Scramble the selected word to create an anagram
        // Make a copy of the word to modify
        string anagram = word;
        for (int j = 0; j < word.length(); j++)
        {
            // Generate a random index within the word length
            int k = rand() % word.length();
            // Swap the characters at indices j and k
            swap(anagram[j], anagram[k]);
        }

        // Display the generated anagram
        cout << "Anagram of the word is: " << anagram << endl;
    }

    // End of the program
    return 0;
}
