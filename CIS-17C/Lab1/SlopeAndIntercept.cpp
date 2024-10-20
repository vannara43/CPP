#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate the slope (m) and intercept (b) using least-squares method
void calculateSlopeIntercept(const vector<double> &deg_f, const vector<double> &deg_c, double &m, double &b)
{
    int n = deg_f.size();
    double sum_f = 0.0, sum_c = 0.0, sum_f_c = 0.0, sum_f_squared = 0.0;

    for (int i = 0; i < n; ++i)
    {
        sum_f += deg_f[i];
        sum_c += deg_c[i];
        sum_f_c += deg_f[i] * deg_c[i];
        sum_f_squared += deg_f[i] * deg_f[i];
    }

    m = (n * sum_f_c - sum_f * sum_c) / (n * sum_f_squared - sum_f * sum_f);
    b = (sum_c - m * sum_f) / n;
}

// Function to read a file with a single column of data
vector<double> readData(const string &filename)
{
    vector<double> data;
    ifstream file(filename);
    double value;

    if (file.is_open())
    {
        while (file >> value)
        {
            data.push_back(value);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }

    return data;
}

// Main function
int main()
{
    string deg_f_file = "deg_f.txt";
    string deg_c_file = "deg_c.txt";

    // Read Fahrenheit and Celsius data
    vector<double> deg_f = readData(deg_f_file);
    vector<double> deg_c = readData(deg_c_file);

    if (deg_f.size() != deg_c.size() || deg_f.empty())
    {
        cout << "Data size mismatch or empty files!" << endl;
        return 1;
    }

    // Variables to store slope (m) and intercept (b)
    double slope = 0.0, intercept = 0.0;

    // Calculate the slope and intercept
    calculateSlopeIntercept(deg_f, deg_c, slope, intercept);

    // Output the results
    cout << fixed << setprecision(5);
    cout << "Slope (m): " << slope << endl;
    cout << "Intercept (b): " << intercept << endl;

    // Write to output file
    ofstream output("output.txt");
    if (output.is_open())
    {
        output << fixed << setprecision(5);
        output << "Slope (m): " << slope << endl;
        output << "Intercept (b): " << intercept << endl;
        output.close();
    }
    else
    {
        cout << "Unable to open output file" << endl;
    }

    return 0;
}
