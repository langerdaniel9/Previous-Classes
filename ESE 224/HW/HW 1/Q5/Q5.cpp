#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double largest = 0;
    bool loop = true;

    cout << "Start entering values:\n";

    while (loop)
    {
        double input;
        cin >> input;
        if (input <= 0)
        {
            loop = false;
            break;
        }

        if (input > largest)
        {
            largest = input;
        }
    }

    largest = (floor(((largest * 100) + .5))) / 100;
    cout << "The largest input was " << largest << "\n";
}