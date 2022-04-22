#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "parallelogram.h"

using namespace prohorcev;

void testShape(std::shared_ptr<Shape> shape);

int main()
{
    setlocale(0, "");
    std::cout << std::setprecision(1) << std::fixed;

    std::shared_ptr<Shape> p1 = std::make_shared<Rectangle>(point_t{ -1.0, -1.0 }, point_t{ 1.0, 1.0 });
    testShape(p1);
    std::shared_ptr<Shape> p2 = std::make_shared<Circle>(point_t{ -1.0, -1.0 }, 15.0);
    testShape(p2);
    std::shared_ptr<Shape> p3 = std::make_shared<Parallelogram>(point_t{ 0.0, 1.0 }, point_t{ 10.0, 1.0 }, point_t{ 5.0, 5.0 });
    testShape(p3);
    return 0;
}

void testShape(std::shared_ptr<Shape> shape)
{
    shape->print_coordinates();
    std::cout << "\nПлощадь фигуры: " << shape->getArea() << "\n\n";
    shape->getFrameRect();
    std::cout << "\n******scale(2.0)*******\n\n";
    shape->scale(2.0);
    shape->print_coordinates();
    std::cout << '\n';
    shape->getFrameRect();
    std::cout << "\nПлощадь фигуры: " << shape->getArea() << '\n';
    std::cout << "\n*****move(3.0, 4.0)****\n\n";
    shape->move(3.0, 4.0);
    shape->print_coordinates();
    std::cout << '\n';
    shape->getFrameRect();
    std::cout << "\n-------------------------------------------------------\n\n";
}