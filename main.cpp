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
#include <curl/curl.h>

using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
/*struct Input {
    vector<double> numbers;
    size_t bin_count;
};*/

int main(int argc, char* argv[])
{
    if(argc>1){
        for (int i=0;i<argc;i++){
            cerr <<"argv["<<i<<"] = "<< argv[i]<< endl;
        }
        return 0;
    }
    curl_global_init(CURL_GLOBAL_ALL);
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
    cin >> bin_count;
    //const auto bins = make_histogram(numbers, bin_count);*/
    const auto input = read_input(cin,true);
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
    return 0;

}
