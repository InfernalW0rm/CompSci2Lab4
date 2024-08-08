#include "Picture.h"

Picture::Picture(int w, int h) : width(w), height(h), pixels(h, vector<Color>(w, Color::WHITE)) {}

void Picture::setPixel(int x, int y, const Color& color) 
{
    if (x < 0 || x >= width || y < 0 || y >= height) throw out_of_range("Coordinate out of range");
    pixels[y][x] = color;
}

int Picture::getHeight() const { return height; }
int Picture::getWidth() const { return width; }

ostream& operator<<(ostream& os, const Picture& picture) 
{
    for (const auto& row : picture.pixels) 
    {
        for (const auto& color : row) 
        {
            os << color;
        }
        os << endl;
    }
    return os;
}
