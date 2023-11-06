#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;
    string fileName;
    string fileData;

    // cout << "Enter file name" << endl;
    // cin >> fileName;

    cout << fileData << endl;

    outputFile.open("D:\\Repositories\\CPP\\test.txt");
    outputFile << "100\n";
    outputFile << "200\n";
    outputFile << "300\n";
    outputFile << "400\n";
    outputFile << "500\n";
    outputFile << "600\n";
    outputFile << "700\n";
    outputFile << "800\n";
    cout << "Data was added to test.txt" << endl;
    outputFile.close();

    inputFile.open("D:\\Repositories\\CPP\\test.txt");
    for (int i = 1; inputFile >> fileData; i++)
    {
        // inputFile >> fileData;
        cout << "i loop: " << i << "-" << fileData << endl;
    }
    inputFile.close();

    return 0;
}

int main()
{
    ifstream inputFile;
    string fileName;
    string data;
    string endpoint;

    cout << "Enter name: ";
    cin >> fileName;
    endpoint = "D:\\Repositories\\CPP\\" + fileName + ".txt";

    inputFile.open(endpoint);
    if (inputFile)
    {
        cout << "Success" << endl;
        while (inputFile >> data)
        {
            cout << data << endl;
        }
    }
    else
    {
        cout << "Nothing is found.";
    }
    return 0;
}