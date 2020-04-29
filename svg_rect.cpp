#include "svg_rect.h"

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />\n";
}

/*
void svg_rect(double x, double y, double width, double height)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='black' fill='black' />";
}
*/
