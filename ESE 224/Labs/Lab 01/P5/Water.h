#pragma

class Water
{
private:
    double current, highest, lowest, average;
    int count;

public:
    Water();
    double getCurrent();
    double getHighest();
    double getLowest();
    double getAverage();
    void newValue(double level);
};
