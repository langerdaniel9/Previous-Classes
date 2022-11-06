#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    double max = 9999999;
    double inside = 0, outside = 0;

    srand(time(NULL));

    for (int i = 0; i < max; i++)
    {
        double x = (double)rand() / (RAND_MAX);
        double y = (double)rand() / (RAND_MAX);

        double length = sqrt((x * x) + (y * y));
        if (length <= 1)
        {
            inside++;
        }
        else
        {
            outside++;
        }
    }

    cout << ((inside / max) * 4) << endl;
}