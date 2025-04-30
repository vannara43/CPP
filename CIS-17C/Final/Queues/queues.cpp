#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// Randomize time within ±50%
float randomize(float rate)
{
    float factor = (rand() % 101 - 50) / 100.0; // Random factor between -0.5 and 0.5
    return rate + rate * factor;
}

struct Clerk
{
    float serviceRate;       // Customers per minute
    float timeRemaining = 0; // Time left to finish the current customer
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed for randomness

    // Simulation parameters
    const float arrivalRate = 4; // Customers per minute
    const float clerk1Rate = 1;
    const float clerk2Rate = 0.5;
    const float clerk3Rate = 0.75;
    const int simulationTime = 120; // 2 hours in minutes

    // Variables for simulation
    queue<float> line; // Queue of customer arrival times
    vector<Clerk> clerks = {{clerk1Rate}, {clerk2Rate}, {clerk3Rate}};
    int maxQueueLength = 0;
    float totalWaitTime = 0;
    int totalCustomers = 0;

    // Simulation loop
    for (int currentTime = 0; currentTime < simulationTime * 60; ++currentTime)
    {
        // Randomize arrival interval
        static float nextArrivalTime = 0;
        if (currentTime >= nextArrivalTime)
        {
            line.push(currentTime);
            nextArrivalTime = currentTime + 60 / randomize(arrivalRate);
        }

        // Serve customers
        for (auto &clerk : clerks)
        {
            if (clerk.timeRemaining <= 0 && !line.empty())
            {
                float arrivalTime = line.front();
                line.pop();
                totalWaitTime += currentTime - arrivalTime;
                ++totalCustomers;
                clerk.timeRemaining = 60 / randomize(clerk.serviceRate);
            }
            if (clerk.timeRemaining > 0)
            {
                clerk.timeRemaining -= 1;
            }
        }

        // Manage clerks dynamically
        int extraClerks = clerks.size() - 3;
        if (line.size() > 5 && extraClerks == 0)
        {
            clerks.push_back({clerk1Rate});
        }
        else if (line.size() <= 5 && extraClerks > 0)
        {
            clerks.pop_back();
        }

        // Track maximum queue length
        maxQueueLength = max(maxQueueLength, static_cast<int>(line.size()));
    }

    // Output results
    cout << fixed << setprecision(2);
    cout << "Simulation Results:" << endl;
    cout << "Average wait time: " << (totalCustomers > 0 ? totalWaitTime / totalCustomers : 0) << " seconds" << endl;
    cout << "Maximum queue length: " << maxQueueLength << endl;

    return 0;
}
