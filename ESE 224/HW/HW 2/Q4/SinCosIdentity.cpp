#include <iostream>
#include <fstream>
#include <cmath>

const double pi = 3.141592653;

using namespace std;

int main()
{
    // Output to sin and cos file
    ofstream sinFile("sin.txt");
    ofstream cosFile("cosine.txt");
    if (sinFile.fail() || cosFile.fail())
    {
        cerr << "Error opening a file";
        exit(1);
    }

    cout << "How many samples to use? (minimum value is 50)" << endl;
    int sampleCount;
    cin >> sampleCount;
    if (cin.fail())
    {
        cout << "Invalid value. Try again";
        exit(2);
    }

    double increment = (2 * pi) / sampleCount;
    for (int i = 0; i <= sampleCount; i++)
    {
        double angleRad = increment * i;

        double sinAngle = (round(sin(angleRad) * 100)) / 100;
        double cosAngle = (round(cos(angleRad) * 100)) / 100;

        sinFile << angleRad << "\t" << sinAngle << endl;
        cosFile << angleRad << "\t" << cosAngle << endl;
    }

    sinFile.close();
    cosFile.close();

    // Read in from sin and cos file to write to result file

    ifstream sinIn("sin.txt");
    ifstream cosIn("cosine.txt");
    ofstream resultFile("result.txt");

    if (sinIn.fail() || cosIn.fail() || resultFile.fail())
    {
        cerr << "Error opening a file";
        exit(1);
    }

    for (int i = 0; i <= sampleCount; i++)
    {
        double sinAngle, cosAngle;
        double sinVal, cosVal;

        sinIn >> sinAngle >> sinVal;
        cosIn >> cosAngle >> cosVal;

        if (sinAngle != cosAngle)
        {
            cerr << "Values dont match up";
            exit(3);
        }

        resultFile << sinAngle << "\t" << ((sinVal * sinVal) + (cosVal * cosVal)) << endl;
    }

    sinIn.close();
    cosIn.close();
    resultFile.close();

    // Calculate rms

    ifstream resultIn("result.txt");

    if (resultIn.fail())
    {
        cerr << "Error opening a file";
        exit(1);
    }

    double sumOfVals = 0, average = 0, count = 0;

    for (int i = 0; i <= sampleCount; i++)
    {
        double angle, value;
        resultIn >> angle >> value;
        value = 1 - value;
        sumOfVals += (value * value);
        count++;
    }

    average = sumOfVals / count;
    average = sqrt(average);

    cout << "The RMS is: " << average;
}