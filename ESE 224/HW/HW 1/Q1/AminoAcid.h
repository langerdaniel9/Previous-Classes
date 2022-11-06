const double O = 15.9994;  // Oxygen
const double C = 12.011;   // Carbon
const double N = 14.00674; // Nitrogen
const double S = 32.066;   // Sulfur
const double H = 01.00794; // Hydrogen

double getWeight(int ox, int ca, int ni, int su, int hy)
{
    return (ox * O) + (ca * C) + (ni * N) + (su * S) + (hy * H);
}