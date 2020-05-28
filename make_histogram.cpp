#include "make_histogram.h"
vector<size_t> make_histogram(Input Data)
//vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count)
{
    double min, max;
    find_minmax(Data.numbers, min, max);
    vector<size_t>count(Data.bin_count, 0);
    for (double x : Data.numbers)
    {
        size_t bin_index = (size_t)(x - min) * (Data.bin_count) / (max - min);
        if (bin_index == Data.bin_count)
        {
            bin_index--;
        }
        count[bin_index]++;
    }
    return count;
}
