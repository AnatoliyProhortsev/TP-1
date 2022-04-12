#include <iostream>
#include "rectangle.h"

using namespace prohorcev;

int main()
{
    setlocale(0, "");

    Rectangle rect(-1.0, -1.0, 1.0, 1.0);
    rect.print_coordinates();
    std::cout << "Площадь прямоугольника: " << rect.getArea() << '\n';
    rect.scale(2.0);
    rect.print_coordinates();
    std::cout<<"Площадь прямоугольника: "<<rect.getArea()<<'\n';
    return 0;
}
