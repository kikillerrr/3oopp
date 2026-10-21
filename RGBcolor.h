#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include <iostream>

// Класс RGBColor представляет цвет в модели RGB.
// Каждый цвет состоит из трёх каналов: красного, зелёного и синего.
class RGBColor {
private:
    int red;    // Красный канал (от 0 до 255)
    int green;  // Зелёный канал (от 0 до 255)
    int blue;   // Синий канал (от 0 до 255)

    // mutable позволяет изменять счётчик даже внутри const-методов.
    mutable int viewCount;

    // Статическая переменная хранит количество созданных объектов класса.
    static int colorCount;

public:
    // Конструктор по умолчанию создаёт чёрный цвет (0, 0, 0).
    RGBColor();

    // Конструктор принимает значения всех трёх RGB-каналов.
    // Значения за пределами диапазона 0–255 должны ограничиваться.
    RGBColor(int r, int g, int b);

    // explicit запрещает неявное преобразование int в RGBColor.
    // Одно число задаёт одинаковую яркость всех каналов.
    explicit RGBColor(int brightness);

    // Конструктор копирования создаёт объект на основе другого цвета.
    RGBColor(const RGBColor& other);

    // Деструктор вызывается при уничтожении объекта.
    ~RGBColor();

    // Геттеры возвращают значения отдельных цветовых каналов.
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    // Возвращает суммарную яркость цвета.
    int getBrightness() const;

    // Статический метод возвращает количество созданных цветов.
    static int getColorCount();

    // Выводит информацию о цвете.
    // Метод const не изменяет обычные поля объекта.
    void printInfo() const;

    // Проверяет, находятся ли каналы в диапазоне от 0 до 255.
    bool isValid() const;
};

#endif // RGBCOLOR_H