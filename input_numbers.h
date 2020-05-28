#pragma once
#include <vector>
#include <iostream>
using namespace std;
struct Input {
    vector<double> numbers;
    size_t bin_count;
};
vector<double> input_numbers(istream&, size_t);
Input read_input(istream&);
