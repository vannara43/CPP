#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

int getRandomNumber(int min, int max)
{
    unsigned seed = time(0);
    srand(seed);
    int randomNum = rand();

    return randomNum;
}

int main()
{

    int damage = getRandomNumber(1, 100);
    int hp = 100;
    float level = 0;
    string playerName = "Angel";
    int playerAtk;
    int playerDef;
    int playerHp;
    int daysToTrain;
    char input;

    cout << "Enter your players name" << endl;
    cin >> playerName;

    cout << "\nWelcome " << playerName << " to the world of PVP" << endl;
    cout << "Whats your atk? " << endl;
    cin >> playerAtk;
    cout << "Whats your def? " << endl;
    cin >> playerDef;
    cout << "Whats your hp? " << endl;
    cin >> playerHp;

    cout << setfill('*') << setw(20) << "" << endl;
    cout << "Players Information" << endl;
    cout << setfill('*') << setw(20) << "" << endl;
    cout << "Player Name:" << playerName << endl;
    cout << "Player Attack:" << playerAtk << endl;
    cout << "Player Def:" << playerDef << endl;
    cout << "Player HP:" << playerHp << endl;

    cout << "What would you like to do?" << playerHp << endl;
    cout << "1: fight or 2: train" << endl;
    cin >> input;

    switch (input)
    {
    case '1':
        int a, b;
        cout << "You decided to fight, get ready!" << endl;
        cout << "You been hit " << damage << endl;
        break;
    case '2':
        cout << "You decided to train!" << endl;
        cout << "How many days do you want to train?" << endl;
        cin >> daysToTrain;
        cout << "You leveled up " << (level + daysToTrain);
        break;
    default: // If enter any value beside 1 and 2
        cout << "I don't know where you went wrong" << endl;
    }

    return 0;
};
