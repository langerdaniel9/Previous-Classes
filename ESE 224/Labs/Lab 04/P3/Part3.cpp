#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    cout << "How many random numbers to generate?" << endl;
    cin >> n;

    srand(time(NULL));

    double min, max;
    double total = 0, average;

    for (int i = 0; i < n; i++)
    {
        double random = ((double)rand() / (RAND_MAX)) + 1;
        cout << random << endl;

        if (i == 0)
        {
            min = max = random;
        }
        else
        {
            if (random < min)
            {
                min = random;
            }
            if (random > max)
            {
                max = random;
            }
        }
        total += random;
    }
    average = total / n;

    cout << "Average is: " << average << endl;
    cout << "Minimum is: " << min << endl;
    cout << "Maximum is: " << max << endl;
}