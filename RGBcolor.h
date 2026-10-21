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

