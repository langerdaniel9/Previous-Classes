#include <iostream>

using namespace std;

int staircase(int steps)
{
    if (steps == 0 || steps == 1)
    {
        return 1;
    }

    return staircase(steps - 1) + staircase(steps - 2);
}

int main()
{
    cout << "5 steps would be: " << staircase(5) << endl;
    cout << "10 steps would be: " << staircase(10) << endl;
    cout << "20 steps would be: " << staircase(20) << endl;
    cout << "30 steps would be: " << staircase(30) << endl;
}