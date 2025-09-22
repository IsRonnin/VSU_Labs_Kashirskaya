#include <iostream>


using std::cin, std::endl, std::cout, std::system; // объявляем поток ввода вывода.



auto main()->int{
    setlocale(LC_ALL, ".UTF8");
    float x(0), y(0); // объявляем переменные.
    
    cout << "Введите x,y через пробел: "; 
    cin >> x >> y; // заполняем переменные.
    
    if (!(((x<=2) && (x>0)) && ((y<=2) && (y>0)) && (x*y >= 1))){
        cout << "Точка x = " << x <<" y = "<< y << " - Не входит в область.\n";
    }else{
        cout << "Точка x = " << x <<" y = "<< y << " - входит в область.\n";
    }


    system("pause");
    return 0;
}