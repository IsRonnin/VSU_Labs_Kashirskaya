//24 ускова паскаль, стр 39, задания для самостоятельной работы.
// Выполнил студент второй группы Туз. А. Е.

#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::system;
using std::powf;
using std::sqrtf;
using std::acosf;
using std::fabs;

auto main()->int{
    setlocale(LC_ALL, ".UTF8"); // Локаль 
    const float TOL = 1e-1;
    float x1(0),y1(0), x2(0), y2(2), x3(0), y3(0); // Координаты
    float side12(0), side23(0), side13(0);
    float sideSqareSum(0), maxSideSqare(0);
    
    cout << "Введите x1, y1 через пробел: "; // уведомляем пользователя о вводе. 
    cin >> x1 >> y1;
    cout << "Введите x2, y2 через пробел: ";
    cin >> x2 >> y2;
    cout << "Введите x3, y3 через пробел: ";
    cin >> x3 >> y3; // записываем переменные. 
    cout << endl; // отступ - перед новыми сообщениями.

    
    if (fabs((x3 - x1) / (x2 - x1) - (y3 - y1) / (y2 - y1)) <= TOL 
    || (fabs(x1-x2)<= TOL && fabs(x2-x3) <= TOL) || (fabs(y1-y2)<= TOL && fabs(y2-y3) <= TOL)) // Точки 1, 2, 3 - лежат на одной прямой
    { 
        cout << "\nЭто не треугольник.\n";
        system("pause");
        return 0;
    }
    cout << "Это ";
    // расчёт сторон - евклидово расстояние
    side12 = sqrtf(powf(x2-x1,2) + powf(y2-y1,2));
    side23 = sqrtf(powf(x2-x3,2) + powf(y2-y3,2));
    side13 = sqrtf(powf(x3-x1,2) + powf(y3-y1,2));

    if(fabs(side12 - side23) <= TOL && fabs(side23 - side13) <= TOL) // проверка сторон
    {
        cout << "равносторонний ";
    }
    else if (fabs(side12 - side23) <= TOL || fabs(side23 - side13) <= TOL || fabs(side12 - side13) <= TOL)
    {
        cout << "равнобедренный ";
    }else
    {
        cout << "разносторонний ";
    }

    
    
    if (side12 - side23 >= TOL && side12 - side13 >= TOL) // расчёт Пифагора) a^2 + b^2 = c^2 где a < c, b < c
    {
        maxSideSqare = powf(side12,2);
        sideSqareSum = powf(side13,2) + powf(side23,2);
    }
    else if(side23 - side12 >= TOL && side23 - side13 >= TOL)
    {
        maxSideSqare = powf(side23,2);
        sideSqareSum = powf(side13,2) + powf(side12,2);
    }
    else
    {
        maxSideSqare = powf(side13,2);
        sideSqareSum = powf(side23,2) + powf(side12,2);
    }
    

    if (fabs(maxSideSqare - sideSqareSum) <= pow(TOL,2)) // проверка по пифогору 
    {
        cout << "прямоугольный ";
    }
    else if (maxSideSqare < sideSqareSum)
    {
        cout << "остроугольный ";
    }
    else
    {
        cout << "тупоугольный ";
    }

    cout << "треугольник\n";

    system("pause");

}