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
    float tempFsort;
    float x1{0},y1{0}, x2{0}, y2{2}, x3{0}, y3{0}; // Координаты
    float side1{0}, side2{0}, side3{0};
    float sideSqareSum{0}, maxSideSqare{0};
    
    cout << "Введите x1, y1 через пробел: "; // уведомляем пользователя о вводе. 
    cin >> x1 >> y1;
    cout << "Введите x2, y2 через пробел: ";
    cin >> x2 >> y2;
    cout << "Введите x3, y3 через пробел: ";
    cin >> x3 >> y3; // записываем переменные. 
    cout << endl; // отступ - перед новыми сообщениями.

    
    if (fabs((x3 - x1) / (x2 - x1) - (y3 - y1) / (y2 - y1)) <= TOL 
    || (fabs(x1-x2)<= TOL && fabs(x2-x3) <= TOL) 
    || (fabs(y1-y2)<= TOL && fabs(y2-y3) <= TOL)) // Точки 1, 2, 3 - лежат на одной прямой
    { 
        cout << "\nЭто не треугольник.\n";
        system("pause");
        return 0;
    }
    cout << "Это ";
    // расчёт сторон - евклидово расстояние
    side1 = sqrtf(powf(x2-x1,2) + powf(y2-y1,2));
    side2 = sqrtf(powf(x2-x3,2) + powf(y2-y3,2));
    side3 = sqrtf(powf(x3-x1,2) + powf(y3-y1,2));

    if (side1 - side2 < TOL){
        tempFsort = side1;
        side1 = side2;
        side2 = tempFsort;
    }
    if (side2 - side3 < TOL){
        tempFsort = side2;
        side2 = side3;
        side3 = tempFsort;
    }
    if (side1 - side2 < TOL){
        tempFsort = side1;
        side1 = side2;
        side2 = tempFsort;
    }

    maxSideSqare = powf(side1,2);
    sideSqareSum = powf(side2,2) + powf(side3,2);

    // проверка сторон
    if(fabs(side1 - side2) <= TOL 
        && fabs(side2 - side3) <= TOL) 
    {
        cout << "равносторонний ";
    }
    else if (fabs(side1 - side2) <= TOL 
            || fabs(side2 - side3) <= TOL)
    {
        cout << "равнобедренный ";
    }else
    {
        cout << "разносторонний ";
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
