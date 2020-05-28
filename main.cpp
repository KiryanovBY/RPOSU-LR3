#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "find_minmax.h"
#include "input_numbers.h"
#include "make_histogram.h"
#include "show_histogram_text.h"
#include "svg_begin.h"
#include "svg_end.h"
#include "svg_text.h"
#include "svg_rect.h"
#include "show_histogram_svg.h"

using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
/*struct Input {
    vector<double> numbers;
    size_t bin_count;
};*/

int main()
{
    /*size_t number_count;
    cerr << "enter number count > ";
    cin >> number_count;
    if (!(number_count > 0)) {
        cerr << "ERROR - Invalid vector length!" << endl;
        exit(0);
    }
    const auto numbers = input_numbers(cin,number_count);

    size_t bin_count;
    cerr << "enter bin count";
    cin >> bin_count;*/
    const auto input = read_input(cin);
    //const auto bins = make_histogram(numbers, bin_count);
    //show_histogram_svg(bins);
    const auto bins = make_histogram(input);
    return 0;

}
