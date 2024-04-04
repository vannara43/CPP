#include <iostream>
#include <iomanip>

using namespace std;

struct WeatherStats
{
    double Total_Rainfall = 0;
    double Total_Snowfall = 0;
    double High_Temperature = 0;
    double Low_Temperature = 0;
    double Average_Temperature = 0;
};

int main()
{
    const int MONTHS = 5;
    WeatherStats WData[MONTHS];
    int avgRainfall = 0;
    int avgSnowfall = 0;
    int totalSumRainfall = 0;
    int totalSumSnowfall = 0;

    for (int i = 0; i < MONTHS; i++)
    {
        cout << "MONTH " << (i + 1) << endl;
        // RAINFALL INPUT
        cout << "Enter total rainfall: ";
        cin >> WData[i].Total_Rainfall;
        while (WData[i].Total_Rainfall < 0)
        {
            cout << "Please enter 0 or higher:";
            cin >> WData[i].Total_Rainfall;
        }
        // SNOWFALL INPUT
        cout << "Enter total snowfall: ";
        cin >> WData[i].Total_Snowfall;
        while (WData[i].Total_Snowfall < 0)
        {
            cout << "Please enter 0 or higher:";
            cin >> WData[i].Total_Snowfall;
        }
        // HIGHEST TEMP INPUT
        cout << "Enter Highest temperature: ";
        cin >> WData[i].High_Temperature;
        while (WData[i].High_Temperature > 150 || WData[i].High_Temperature < -150)
        {
            cout << "Please enter a value between -150 and 150: ";
            cin >> WData[i].High_Temperature;
        }
        // LOWEST TEMP INPUT
        cout << "Enter Lowest temperature: ";
        cin >> WData[i].Low_Temperature;
        while (WData[i].Low_Temperature > 150 || WData[i].Low_Temperature < -150)
        {
            cout << "Please enter a value between -150 and 150: ";
            cin >> WData[i].Low_Temperature;
        }
    }

    // AVERAGE TEMP
    cout << endl;
    cout << "AVERAGE TEMPERATURE FOR EACH MONTH" << endl;
    double totalAverageTemp = 0;
    for (int i = 0; i < MONTHS; i++)
    {
        WData[i].Average_Temperature = (WData[i].High_Temperature + WData[i].Low_Temperature) / 2;
        cout << "Month " << (i + 1) << " average: " << WData[i].Average_Temperature << endl;
        totalAverageTemp += WData[i].Average_Temperature;
    }
    cout << "Total Average of all monthly average temperature: " << (totalAverageTemp / MONTHS) << endl;

    // RAINFALL
    cout << endl;
    cout << "RAINFALL STATS" << endl;
    for (int i = 0; i < MONTHS; i++)
    {
        avgRainfall += (WData[i].Total_Rainfall);
    }
    cout << "Monthly average for rainfall: " << (avgRainfall /= MONTHS) << endl;
    cout << "Total rainfall for the year: " << avgRainfall << endl;

    // SNOWFALL
    cout << endl;
    cout << "SNOWFALL STATS" << endl;
    for (int i = 0; i < MONTHS; i++)
    {
        avgSnowfall += (WData[i].Total_Snowfall);
    }
    cout << "Monthly average for snowfall: " << (avgSnowfall /= MONTHS) << endl;
    cout << "Total rainfall for the year: " << avgSnowfall << endl;

    // FINDING HIGHEST OCCURENCE
    int highest = WData[0].High_Temperature; // Initialize highest with first index
    int highestIndex = 0;                    // Placeholder for what month
    for (int i = 0; i < MONTHS; i++)
    {
        for (int j = i + 1; j < MONTHS; j++)
        {
            if (highest < WData[j].High_Temperature)
            {
                highest = WData[j].High_Temperature;
                highestIndex = j;
            }
        }
    }

    // FINDING LOWEST OCCURENCE
    int lowest = WData[0].Low_Temperature; // Initialize lowest with first index
    int lowestIndex = 0;                   // Placeholder for what month
    for (int i = 0; i < MONTHS; i++)
    {
        for (int j = i + 1; j < MONTHS; j++)
        {
            if (lowest > WData[j].Low_Temperature)
            {
                lowest = WData[j].Low_Temperature;
                lowestIndex = j;
            }
        }
    }

    cout << endl;
    // SWITCH CASE
    cout << "HIGHEST & LOWEST MONTH" << endl;
    switch (highestIndex + 1)
    {
    case 1:
        cout << "January is the highest month with " << highest << " temperature." << endl;
        break;
    case 2:
        cout << "February is the highest month with " << highest << " temperature." << endl;
        break;
    case 3:
        cout << "March is the highest month with " << highest << " temperature." << endl;
        break;
    case 4:
        cout << "April is the highest month with " << highest << " temperature." << endl;
        break;
    case 5:
        cout << "May is the highest month with " << highest << " temperature." << endl;
        break;
    case 6:
        cout << "June is the highest month with " << highest << " temperature." << endl;
        break;
    case 7:
        cout << "July is the highest month with " << highest << " temperature." << endl;
        break;
    case 8:
        cout << "August is the highest month with " << highest << " temperature." << endl;
        break;
    case 9:
        cout << "September is the highest month with " << highest << " temperature." << endl;
        break;
    case 10:
        cout << "October is the highest month with " << highest << " temperature." << endl;
        break;
    case 11:
        cout << "November is the highest month with " << highest << " temperature." << endl;
        break;
    case 12:
        cout << "December is the highest month with " << highest << " temperature." << endl;
        break;

    default:
        break;
    }

    // SWITCH CASE
    switch (lowestIndex + 1)
    {
    case 1:
        cout << "January is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 2:
        cout << "February is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 3:
        cout << "March is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 4:
        cout << "April is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 5:
        cout << "May is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 6:
        cout << "June is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 7:
        cout << "July is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 8:
        cout << "August is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 9:
        cout << "September is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 10:
        cout << "October is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 11:
        cout << "November is the lowest month with " << lowest << " temperature." << endl;
        break;
    case 12:
        cout << "December is the lowest month with " << lowest << " temperature." << endl;
        break;

    default:
        break;
    }

    return 0;
}