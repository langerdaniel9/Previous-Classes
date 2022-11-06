#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    double smallest = __DBL_MAX__;

    for (int i = 0; i < 7; i++)
    {
        cout << "Enter the value for day " << (i + 1) << endl;

        double input;
        cin >> input;

        if (input < smallest)
        {
            smallest = input;
        }
    }

    cout << fixed << setprecision(1);
    cout << "The smallest input was " << smallest << "\n";
}