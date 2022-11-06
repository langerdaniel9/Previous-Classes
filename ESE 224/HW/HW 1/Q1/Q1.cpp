#include "AminoAcid.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    int ox, ca, ni, su, hy;
    cout << "Enter the number of atoms of each element in order (oxygen, carbon, nitrogen, sulfur, hydrogen:" << endl;
    cin >> ox >> ca >> ni >> su >> hy;

    double totalWeight = getWeight(ox, ca, ni, su, hy);

    cout << fixed << setprecision(3) << "The molecular weight for this amino acid is " << totalWeight << " amu." << endl;
}