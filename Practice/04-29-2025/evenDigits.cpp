#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++) // Loop thru vector
        {
            int checkNum = nums[i]; // Get the current number to check
            int evenNumCount = 0;   // Variable to count how many digits this number has

            cout << "Number: " << checkNum << endl;
            while (checkNum != 0) // Counts the digit by removing the last digit
            {
                checkNum /= 10; // Remove the last digit
                evenNumCount++; // Increment digit count
                cout << "Current Number: " << checkNum << " Digit Count: " << evenNumCount << endl;
            }

            cout << "Remainder: " << evenNumCount % 2 << endl;
            // If the number of digits is even, increment the final count
            if (evenNumCount % 2 == 0)
            {
                count++;
            }
        }

        return count; // Return how many numbers had an even number of digits
    }
};

int main()
{
    // Define a vector of integers to test the function
    vector<int> nums = {5000};

    Solution solution;                       // Create an instance of the Solution class
    int result = solution.findNumbers(nums); // Call the findNumbers function with nums

    // Print the result to the console
    cout << "Number of even digits: " << result << endl;

    return 0; // End of program
}
