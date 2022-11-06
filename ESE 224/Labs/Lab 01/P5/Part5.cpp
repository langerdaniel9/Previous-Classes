#include "Water.cpp"
#include <iostream>
using namespace std;

int main()
{
    Water monitor;
    cout << "Current water level: " << monitor.getCurrent() << endl;
    cout << "Average water level: " << monitor.getAverage() << endl;
    cout << "Highest water level: " << monitor.getHighest() << endl;
    cout << "Lowest water level: " << monitor.getLowest() << endl;

    double level;
    // assume there are 10 data back per day
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a new water level for data point " << i + 1 << " : " << endl;
        cin >> level;
        monitor.newValue(level);
    }

    cout << "Current water level: " << monitor.getCurrent() << endl;
    cout << "Average water level: " << monitor.getAverage() << endl;
    cout << "Highest water level: " << monitor.getHighest() << endl;
    cout << "Lowest water level: " << monitor.getLowest() << endl;

    return 0;
}
