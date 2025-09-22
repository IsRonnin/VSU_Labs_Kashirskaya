#include <print>
#include <iostream>

#define Z 0.0000001

using std::cin, std::endl, std::print, std::system; // объявляем поток ввода вывода.



auto main()->int{
    
    float x(0), y(0); // объявляем переменные.
    print("Введите x,y через пробел: "); // endl <=> \n
    cin >> x >> y; // заполняем переменные.
    
    if (!((((x-2)<=Z) && (x>0)) && (((y-2)<=Z) && (y>0)) && ((x*y-1) >= Z))){
        print("Точка x = {}, y = {} - Не входит в область.", x, y);
    }else{
        print("Точка x = {}, y = {} - входит в область.", x, y);
    }


    system("pause");
    return 0;
}