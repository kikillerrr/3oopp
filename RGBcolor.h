#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <iostream>

class RGBColor {

private:
    int red;
    int green;
    int blue;

    mutable int viewCount;
    static int colorCount;

public:
    RGBColor();
    RGBColor(int r, int g, int b);
    explicit RGBColor(int brightness);
    RGBColor(const RGBColor& other);

    ~RGBColor();
};

#endif
