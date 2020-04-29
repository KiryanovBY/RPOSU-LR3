#include "make_histogram.h"

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
{
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t>count(bin_count, 0);
    for (double x : numbers)
    {
        size_t bin_index = (size_t)(x - min) * (bin_count) / (max - min);
        if (bin_index == bin_count)
        {
            bin_index--;
        }
        count[bin_index]++;
    }
    return count;
}