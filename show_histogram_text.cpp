#include "show_histogram_text.h"

void show_histogram_text(const vector<size_t>& bins)
{
    for (size_t bin : bins)
    {
        if (bin < 10)
            cout << " ";
        else if (bin < 100)
            cout << " ";
        cout << bin << "|";

        for (size_t i = 0; i < bin; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}