#include "Water.h"

Water::Water()
{
    current = -1;
    average = -1;
    lowest = -1;
    highest = -1;
    count = -1;
}

double Water::getCurrent() { return current; }
double Water::getHighest() { return highest; }
double Water::getLowest() { return lowest; }
double Water::getAverage() { return average; }
void Water::newValue(double level)
{
    if (count == -1)
    {
        lowest = level;
        highest = level;
        current = level;
        average = level;
        count = 0;
        return;
    }

    if (level < lowest)
    {
        lowest = level;
    }
    if (level > highest)
    {
        highest = level;
    }
    current = level;
    count++;

    average = ((count * average) + current) / (count + 1);
}
