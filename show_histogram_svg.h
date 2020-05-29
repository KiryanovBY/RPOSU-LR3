#pragma once
#include <vector>
#include "svg_begin.h"
#include "svg_end.h"
#include "svg_text.h"
#include "svg_rect.h"
#include <string>
#include <sstream>
#include <cstdio>
#include <windows.h>

using namespace std;
string make_info_text();
void show_histogram_svg(const vector<size_t>&);
