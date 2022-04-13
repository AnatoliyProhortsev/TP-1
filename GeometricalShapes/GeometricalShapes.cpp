#include <iostream>
#include "rectangle.h"
#include "circle.h"

using namespace prohorcev;

void testShape(std::shared_ptr<Shape> shape);

int main()
{
    setlocale(0, "");

    std::shared_ptr<Shape> p1 = std::make_shared<Rectangle>(-1.0, -1.0, 1.0, 1.0);
    testShape(p1);
    std::shared_ptr<Shape> p2 = std::make_shared<Circle>(-1.0, -1.0, 15.0);
    testShape(p2);
    return 0;
}

void testShape(std::shared_ptr<Shape> shape)
{
    shape->print_coordinates();
    std::cout << "Площадь фигуры: " << shape->getArea() << '\n';
    shape->scale(2.0);
    shape->print_coordinates();
    std::cout << "Площадь фигуры: " << shape->getArea() << '\n';
    std::cout << "move(3.0, 4.0): \n";
    shape->move(3.0, 4.0);
    shape->print_coordinates();
}