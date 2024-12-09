#include <iostream>
#include <iomanip>

using namespace std;

int calculatePoints(int placement, int eliminations)
{
    int points = eliminations; // Each elimination gives +1 point

    // Cumulative points based on placement
    if (placement == 1)
        points += 10 + 7 + 5 + 5 + 5 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement == 2)
        points += 7 + 5 + 5 + 5 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement == 3)
        points += 5 + 5 + 5 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement == 4 || placement == 5)
        points += 5 + 5 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement == 6 || placement == 7 || placement == 8 || placement == 9 || placement == 10)
        points += 3 + 3 + 3 + 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement <= 15)
        points += 3 + 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement <= 20)
        points += 3 + 3 + 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement <= 25)
        points += 2 + 2 + 2 + 2 + 2 + 2;
    else if (placement <= 30)
        points += 2 + 2 + 2 + 2 + 2;
    else if (placement <= 35)
        points += 2 + 2 + 2 + 2;
    else if (placement <= 40)
        points += 2 + 2 + 2;
    else if (placement <= 50)
        points += 2 + 2;
    else if (placement <= 75)
        points += 2;

    return points;
}

int main()
{
    int totalPoints = 0;

    for (int game = 1; game <= 7; ++game)
    {
        int placement, eliminations;
        cout << "\nGame " << game << endl;
        cout << "Enter your placement (1-100): ";
        cin >> placement;
        cout << "Enter the number of eliminations: ";
        cin >> eliminations;

        if (placement < 1 || placement > 100 || eliminations < 0)
        {
            cout << "Invalid input. Please enter a valid placement (1-100) and non-negative eliminations.\n";
            --game; // Repeats current game input if input is invalid
            continue;
        }

        int gamePoints = calculatePoints(placement, eliminations);
        totalPoints += gamePoints;

        cout << "Points for Game " << game << ": " << gamePoints << endl;
        cout << "Total Points after Game " << game << ": " << totalPoints << endl;
    }

    cout << "\nFinal Total Points after 7 games: " << totalPoints << endl;
    return 0;
}