#include "RGBcolor.h"

// Инициализация статического поля
int RGBColor::colorCount = 0;

// Конструктор по умолчанию
RGBColor::RGBColor()
    : red(0), green(0), blue(0), viewCount(0)
{
    ++colorCount;
    std::cout << "Создан цвет по умолчанию (0, 0, 0). "
              << "Всего объектов: " << colorCount << "\n";
}

 // Параметризованный конструктор
RGBColor::RGBColor(int r, int g, int b)
    : red(r), green(g), blue(b), viewCount(0)
{
    if (red < 0) red = 0;
    if (red > 255) red = 255;

    if (green < 0) green = 0;
    if (green > 255) green = 255;

    if (blue < 0) blue = 0;
    if (blue > 255) blue = 255;

    ++colorCount;

    std::cout << "Создан цвет (" << red << ", "
              << green << ", " << blue << "). "
              << "Всего объектов: " << colorCount << "\n";
}


 // Explicit-конструктор для создания серого цвета
RGBColor::RGBColor(int brightness)
    : red(brightness), green(brightness),
      blue(brightness), viewCount(0)
{
    if (red < 0) red = 0;
    if (red > 255) red = 255;

    green = red;
    blue = red;

    ++colorCount;

    std::cout << "Создан серый цвет (" << red << ", "
              << green << ", " << blue << "). "
              << "Всего объектов: " << colorCount << "\n";
}


 // Конструктор копирования
RGBColor::RGBColor(const RGBColor& other)
    : red(other.red),
      green(other.green),
      blue(other.blue),
      viewCount(0)
{
    ++colorCount;

    std::cout << "Создан цвет (копия). "
              << "Всего объектов: " << colorCount << "\n";
}
