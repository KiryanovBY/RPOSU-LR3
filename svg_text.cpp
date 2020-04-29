#include "svg_text.h"

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>\n";
}