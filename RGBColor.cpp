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

 // Деструктор
RGBColor::~RGBColor()
{
    --colorCount;

    std::cout << "Удалён цвет. Осталось объектов: "
              << colorCount << "\n";
}

 // Методы получения значений цветовых каналов
int RGBColor::getRed() const {
    return red;
}

int RGBColor::getGreen() const {
    return green;
}

int RGBColor::getBlue() const {
    return blue;
}

// Получение яркости цвета
int RGBColor::getBrightness() const {
    return red + green + blue;
}

// Получение количества живых объектов
int RGBColor::getColorCount() {
    return colorCount;
}


 // Префиксный инкремент ++color
RGBColor& RGBColor::operator++() {
    if (red < 255) ++red;
    if (green < 255) ++green;
    if (blue < 255) ++blue;

    return *this;
}

// Префиксный декремент --color
RGBColor& RGBColor::operator--() {
    if (red > 0) --red;
    if (green > 0) --green;
    if (blue > 0) --blue;

    return *this;
}

 // Постфиксный инкремент color++
RGBColor RGBColor::operator++(int) {
    RGBColor old = *this;
    ++(*this);
    return old;
}

// Постфиксный декремент color--
RGBColor RGBColor::operator--(int) {
    RGBColor old = *this;
    --(*this);
    return old;
}

 // Сложение с присваиванием
RGBColor& RGBColor::operator+=(const RGBColor& other) {
    red += other.red;
    green += other.green;
    blue += other.blue;

    if (red > 255) red = 255;
    if (green > 255) green = 255;
    if (blue > 255) blue = 255;

    return *this;
}

// Вычитание с присваиванием
RGBColor& RGBColor::operator-=(const RGBColor& other) {
    red -= other.red;
    green -= other.green;
    blue -= other.blue;

    if (red < 0) red = 0;
    if (green < 0) green = 0;
    if (blue < 0) blue = 0;

    return *this;
}
RGBColor& RGBColor::operator*=(const RGBColor& other) {
    red = (red * other.red) / 255;
    green = (green * other.green) / 255;
    blue = (blue * other.blue) / 255;

    return *this;
}

RGBColor& RGBColor::operator/=(const RGBColor& other) {
    if (other.red != 0) {
        red = (red * 255) / other.red;
        if (red > 255) red = 255;
    }

    if (other.green != 0) {
        green = (green * 255) / other.green;
        if (green > 255) green = 255;
    }

    if (other.blue != 0) {
        blue = (blue * 255) / other.blue;
        if (blue > 255) blue = 255;
    }

    return *this;
}