#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("data3.dat");
    if (fin.fail())
    {
        cerr << "Error opening input file!";
        exit(1);
    }

    ofstream fout("data3report.dat");
    if (fout.fail())
    {
        cerr << "Error opening output file!";
        exit(1);
    }

    // Things for data1report.dat
    double maxArea, maxAreaW, maxAreaH;
    double minArea, minAreaW, minAreaH;
    double squareNum, squareTotal, averageAreaSquare;
    double rectNum, rectTotal, averageAreaRect;
    int count = 0;

    string line;
    getline(fin, line);
    do
    {
        double width, height;
        width = stod(line.substr(0, line.find(" ")));
        height = stod(line.substr(line.find(" "), line.length()));

        bool square = (width == height);
        double area = width * height;

        if (count == 0)
        {
            maxArea = minArea = area;
            maxAreaW = minAreaW = width;
            maxAreaH = minAreaW = height;
        }
        else
        {
            if (area > maxArea)
            {
                maxArea = area;
                maxAreaW = width;
                maxAreaH = height;
            }
            else if (area < minArea)
            {
                minArea = area;
                minAreaW = width;
                minAreaH = height;
            }
        }

        if (square)
        {
            squareNum++;
            squareTotal += area;
        }
        else
        {
            rectNum++;
            rectTotal += area;
        }
        count++;
    } while (getline(fin, line));

    averageAreaRect = rectTotal / rectNum;
    averageAreaSquare = squareTotal / squareNum;

    fout << "Minimum area is: " << setw(5) << minArea << " with dimensions: " << setw(4) << minAreaW << " * " << setw(4) << minAreaH << endl;
    fout << "Maximum area is: " << setw(5) << maxArea << " with dimensions: " << setw(4) << maxAreaW << " * " << setw(4) << maxAreaH << endl;
    fout << "Average area of rectangles is: " << averageAreaRect << endl;
    fout << "Average area of squares is: " << averageAreaSquare << endl;
    cout << "Data outputted to file" << endl;

    return 0;
}