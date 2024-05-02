#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    // VARIABLE DECLARATIONs
    ifstream inputFile;
    ofstream outputFile;
    string inputName;
    string outputName;
    string searchName;
    string endpointIn;
    string endpointOut;
    string fullName[20];
    string firstName[10];
    string lastName[10];
    string storedId[10];
    string storedBalance[10];
    string foundName[10];
    string foundId[10];
    string foundBalance[10];
    bool foundActive = false;
    bool searchActive = false;
    bool isFileDataLoaded = false;
    float averageBalanceDue = 0;
    int count = 0;
    int foundCount = 0;

    // INPUT VARIABLE
    cout << left << setw(40) << "What input file would you like to use?";
    cin >> inputName;
    cout << left << setw(41) << "What output file would you like to use?";
    cin >> outputName;
    endpointIn = "D:\\Repositories\\CPP\\" + inputName;
    endpointOut = "D:\\Repositories\\CPP\\" + outputName;

    // OPEN TEXT FILE
    inputFile.open(endpointIn);
    if (inputFile)
    {

        for (count = 0; count <= 19; count++)
        {
            inputFile >> firstName[count] >> lastName[count] >> storedId[count] >> storedBalance[count];

            fullName[count] = firstName[count] + " " + lastName[count];
        }
        inputFile.close();

        isFileDataLoaded = true;
        cout << "Successfully loaded data to Input File Data." << endl
             << endl;
    }
    else // NO FILE WAS FOUND
    {
        cout << "Error opening the file." << endl;
        return 0;
    }

    // VALIDATE IF DATA EXISTS
    if (isFileDataLoaded)
    {
        searchActive = true;
        cin.ignore();
        while (searchActive)
        {
            cout << "Who do you want to search for (enter done to exit): ";
            getline(cin, searchName);

            // CHECK FOR "DONE"
            if (searchName == "done" || searchName == "Done")
            {
                cout << "Thank you for using my program";
                break;
            }
            else if (searchName != "done")
            {
                for (count = 0; count <= 19; count++)
                {
                    // CHECK FOR NAME IS FOUND
                    if (count < 19 && searchName == fullName[count])
                    {
                        cout << "Found" << endl;
                        foundName[foundCount] = fullName[count];
                        foundId[foundCount] = storedId[count];
                        foundBalance[foundCount] = storedBalance[count];
                        foundCount++;
                        foundActive = true;
                        break;
                    }
                    // NOT FOUND
                    else if (count == 19 && searchName != fullName[count])
                    {
                        cout << "Not in database." << endl;
                    }
                }
            }
        }
        if (foundActive)
        {
            // OPEN OUTPUT FILE
            outputFile.open(endpointOut);

            // DISPLAY TITLE
            outputFile << left << setw(9) << "ID #" << setw(25) << "NAME" << setw(11) << "BALANCE DUE" << endl;
            outputFile << left << setw(9) << "____" << setw(25) << "____________________" << setw(11) << "___________" << endl;

            // DISPLAY OUTPUT
            for (count = 0; count < foundCount; count++)
            {
                outputFile << setw(9) << left << foundId[count] << setw(25) << foundName[count] << "$" << setw(10) << right << setprecision(2) << showpoint << fixed << stof(foundBalance[count]) << endl;
            }
            // CALCULATION FOR AVERAGE DUE
            for (count = 0; count < foundCount; count++)
            {
                float balance = stof(foundBalance[count]);
                averageBalanceDue = averageBalanceDue + balance;
            }

            // DISPLAY AVERAGE BALANCE DUE
            outputFile << "\n";
            outputFile << setw(34) << right << setprecision(2) << fixed
                       << "AVERAGE BALANCE DUE: "
                       << "$" << setw(10) << (averageBalanceDue / foundCount) << endl;

            // CLOSE OUTPUT FILE
            outputFile.close();
        }
    }

    return 0;
}
