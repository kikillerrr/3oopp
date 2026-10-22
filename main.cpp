#include "RGBColor.h"
#include <iostream>
#include <windows.h>

/**
 * @brief Точка входа — тест класса RGBColor
 * 
 * Демонстрирует:
 * - 3 конструктора (по умолчанию, параметризованный, explicit, копирования)
 * - унарные операции ++ и -- (префикс и постфикс)
 * - арифметическое присваивание +=, -=, *=, /=
 * - бинарные операции +, -, *, /
 * - сравнение <, >, <=, >=, ==, !=
 * - explicit (запрет неявного преобразования)
 * - mutable (изменение в const-объекте)
 * - статический счётчик объектов
 * 
 * @return 0 при успешном завершении
 */
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

   
    
    // 3 КОНСТРУКТОРА 
    std::cout << " СОЗДАНИЕ (3 конструктора) \n\n";
    RGBColor c1;
    RGBColor c2(100, 150, 200);
    RGBColor c3(c2);
    RGBColor c4(120);
    
    std::cout << "\n--- Начальное состояние ---\n";
    c1.printInfo();
    c2.printInfo();
    c3.printInfo();
    c4.printInfo();
    
    // УНАРНЫЕ 
    std::cout << "\n УНАРНЫЕ ОПЕРАЦИИ \n\n";
    std::cout << "c2 до: ";
    c2.printInfo();
    
    ++c2;
    std::cout << "++c2: ";
    c2.printInfo();
    
    c2++;
    std::cout << "c2++: ";
    c2.printInfo();
    
    --c2;
    std::cout << "--c2: ";
    c2.printInfo();
    
    c2--;
    std::cout << "c2--: ";
    c2.printInfo();
    
    //  += -= *= /= 
    std::cout << "\n АРИФМЕТИЧЕСКОЕ ПРИСВАИВАНИЕ \n\n";
    RGBColor t1(50, 50, 50);
    RGBColor t2(30, 30, 30);
    
    std::cout << "t1: ";
    t1.printInfo();
    
    t1 += t2;
    std::cout << "t1 += t2: ";
    t1.printInfo();
    
    t1 -= t2;
    std::cout << "t1 -= t2: ";
    t1.printInfo();
    
    t1 *= 2;
    std::cout << "t1 *= 2: ";
    t1.printInfo();
    
    t1 /= 2;
    std::cout << "t1 /= 2: ";
    t1.printInfo();
    
    // БИНАРНЫЕ 
    std::cout << "\n БИНАРНЫЕ ОПЕРАЦИИ \n\n";
    RGBColor a(10, 20, 30);
    RGBColor b(40, 50, 60);
    
    RGBColor s = a + b;
    std::cout << "a + b: ";
    s.printInfo();
    
    RGBColor d = b - a;
    std::cout << "b - a: ";
    d.printInfo();
    
    RGBColor m = a * 3;
    std::cout << "a * 3: ";
    m.printInfo();
    
    RGBColor q = b / 2;
    std::cout << "b / 2: ";
    q.printInfo();
    
    // СРАВНЕНИЕ 
    std::cout << "\n СРАВНЕНИЕ\n\n";
    RGBColor small(50, 50, 50);
    RGBColor big(100, 100, 100);
    
    std::cout << "small < big: " << (small < big ? "true" : "false") << "\n";
    std::cout << "small > big: " << (small > big ? "true" : "false") << "\n";
    std::cout << "small <= big: " << (small <= big ? "true" : "false") << "\n";
    std::cout << "small >= big: " << (small >= big ? "true" : "false") << "\n";
    std::cout << "small == big: " << (small == big ? "true" : "false") << "\n";
    std::cout << "small != big: " << (small != big ? "true" : "false") << "\n";
    
    //EXPLICIT запрещает неявное преобразование числа
    std::cout << "\n EXPLICIT\n\n";
    // RGBColor bad = 150;
    RGBColor good(150);
    std::cout << "good (explicit): ";
    good.printInfo();
    

    // MUTABLE + CONST
    std::cout << "\n MUTABLE + CONST объект \n\n";
    const RGBColor constColor(70, 80, 90);
    std::cout << "constColor (const, но viewCount растёт):\n";
    constColor.printInfo();
    constColor.printInfo();
    constColor.printInfo();
    
    // СТАТИЧЕСКИЙ СЧЁТЧИК 
    std::cout << "\n  СТАТИЧЕСКИЙ СЧЁТЧИК \n\n";
    std::cout << "Сколько всего цветов: " << RGBColor::getColorCount() << "\n";
    
    std::cout << "\n КОНЕЦ ТЕСТА \n\n";
    return 0;
}