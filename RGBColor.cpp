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
