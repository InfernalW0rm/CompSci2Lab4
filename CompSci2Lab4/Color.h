#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

class Color 
{
public:
    int red, green, blue;

    Color(int r, int g, int b);

    static const Color RED, YELLOW, BLUE, GREEN, PURPLE, ORANGE, BLACK, WHITE, GRAY;

    friend ostream& operator<<(ostream& os, const Color& color);
};

#endif
