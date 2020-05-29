#include <iostream>
#include <sstream>
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

size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    const char* Items = reinterpret_cast<const char*>(items);
    size_t data_size = item_size * item_count;
    buffer->write(Items, data_size);
    return data_size;
}

Input download(const string& address) {
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
        CURL * curl = curl_easy_init();
        if(curl) {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            res = curl_easy_perform(curl);
            if(res){
                cerr<<curl_easy_strerror(res)<<endl;
                exit(1);
            }
            double dl;
            res = curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &dl);
            if(!res) cerr<< "Downloaded "<<dl<<" bytes" << endl;
            curl_easy_cleanup(curl);
        }
    return read_input(buffer, false);
}

int main(int argc, char* argv[])
{
    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);
    }
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);

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
    /*const auto input = read_input(cin,true);
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
    */
    return 0;
}
