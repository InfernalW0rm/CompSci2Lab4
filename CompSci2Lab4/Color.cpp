#include "Color.h"

const Color Color::RED(255, 0, 0);
const Color Color::YELLOW(255, 255, 0);
const Color Color::BLUE(0, 0, 255);
const Color Color::GREEN(0, 255, 0);
const Color Color::PURPLE(150, 0, 255);
const Color Color::ORANGE(255, 150, 0);
const Color Color::BLACK(0, 0, 0);
const Color Color::WHITE(255, 255, 255);
const Color Color::GRAY(150, 150, 150);

Color::Color(int r, int g, int b) : red(r), green(g), blue(b) {}

ostream& operator<<(ostream& os, const Color& color) 
{
    if (color.red == color.green && color.green == color.blue) 
    {
        if (color.red > 250) 
        {
            os << 'W';
        }
        else if (color.red < 50) 
        {
            os << 'D';
        }
        else {
            os << 'G';
        }
    }
    else if (color.red >= color.green && color.red >= color.blue) 
    {
        if (color.green == color.blue) 
        {
            os << 'P';
        }
        else {
            os << 'R';
        }
    }
    else if (color.green >= color.red && color.green >= color.blue) 
    {
        if (color.red == color.blue) 
        {
            os << 'Y';
        }
        else {
            os << 'V';
        }
    }
    else {
        if (color.red == color.green) 
        {
            os << 'T';
        }
        else {
            os << 'B';
        }
    }
    return os;
}
