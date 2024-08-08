#ifndef PICTURE_H
#define PICTURE_H

#include "Color.h"
#include <vector>
#include <iostream>

using namespace std;

class Picture 
{
    vector<vector<Color>> pixels;
    int width, height;

public:
    Picture(int w, int h);

    void setPixel(int x, int y, const Color& color);

    int getHeight() const;
    int getWidth() const;

    friend ostream& operator<<(ostream& os, const Picture& picture);
};

#endif
