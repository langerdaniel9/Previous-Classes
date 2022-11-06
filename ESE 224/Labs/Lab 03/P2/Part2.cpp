#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("data1.dat");
    if (fin.fail())
    {
        cerr << "Error opening input file!";
        exit(1);
    }

    ofstream fout("data1report.dat");
    if (fout.fail())
    {
        cerr << "Error opening output file!";
        exit(1);
    }

    int lines;
    fin >> lines;

    // Things for data1report.dat
    double maxArea, maxAreaW, maxAreaH;
    double minArea, minAreaW, minAreaH;
    double squareNum, squareTotal, averageAreaSquare;
    double rectNum, rectTotal, averageAreaRect;

    for (int i = 0; i < lines; i++)
    {
        double width, height;
        fin >> width >> height;

        bool square = (width == height);
        double area = width * height;

        if (i == 0)
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
    }

    averageAreaRect = rectTotal / rectNum;
    averageAreaSquare = squareTotal / squareNum;

    fout << "Minimum area is: " << setw(5) << minArea << " with dimensions: " << setw(4) << minAreaW << " * " << setw(4) << minAreaH << endl;
    fout << "Maximum area is: " << setw(5) << maxArea << " with dimensions: " << setw(4) << maxAreaW << " * " << setw(4) << maxAreaH << endl;
    fout << "Average area of rectangles is: " << averageAreaRect << endl;
    fout << "Average area of squares is: " << averageAreaSquare << endl;
    cout << "Data outputted to file" << endl;

    return 0;
}