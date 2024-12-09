#include <iostream>
#include <iomanip>

using namespace std;

int calculatePoints(int placement, int eliminations)
{
    int points = eliminations; // Each elimination gives +1 point

    // Cumulative points based on placement
    if (placement == 1)
        points += 5 + 2 + 2 + 1 + 1 + 1 + 1 + 1 + 1;
    else if (placement == 2)
        points += 2 + 2 + 1 + 1 + 1 + 1 + 1 + 1;
    else if (placement == 3)
        points += 2 + 1 + 1 + 1 + 1 + 1 + 1;
    else if (placement == 4)
        points += 1 + 1 + 1 + 1 + 1 + 1;
    else if (placement == 5)
        points += 1 + 1 + 1 + 1 + 1;
    else if (placement == 6)
        points += 1 + 1 + 1 + 1;
    else if (placement == 7)
        points += 1 + 1 + 1;
    else if (placement == 8)
        points += 1 + 1;
    else if (placement == 9)
        points += 1;

    return points;
}

int main()
{
    int totalPoints = 0;

    for (int game = 1; game <= 7; ++game)
    { // 7 games in the tournament

        int placement, eliminations;
        cout << "\nGame " << game << endl;
        cout << "Enter your placement (1-40): ";
        cin >> placement;
        cout << "Enter the number of eliminations: ";
        cin >> eliminations;

        if (placement < 1 || placement > 40 || eliminations < 0)
        {
            cout << "Invalid input. Please enter a valid placement (1-40) and non-negative eliminations.\n";
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
