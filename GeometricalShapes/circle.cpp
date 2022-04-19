#include "circle.h"

using namespace prohorcev;

Circle::Circle(double x_center, double y_center, double radius)
{
	if (radius <= 0)
	{
		std::cout << "Введён неверный радиус при создании круга. Создание круга (0,0,0)\n";
		m_rect.height = 0;
		m_rect.width = 0;
		m_rect.pos.x = 0;
		m_rect.pos.y = 0;
	}
	else
	{
		m_rect.pos.x = x_center;
		m_rect.pos.y = y_center;

		m_rect.height = 2 * radius;
		m_rect.width = m_rect.height;
	}
	
}

double Circle::getArea()
{
	return m_rect.height * m_rect.height / 4 * 3.14;
}

rectangle_t Circle::getFrameRect()
{
	return m_rect;
}

void Circle::move(point_t pos)
{
	m_rect.pos = pos;
}

void Circle::move(double offset_x, double offset_y)
{
	m_rect.pos.x += offset_x;
	m_rect.pos.y += offset_y;
}

void Circle::scale(double coefficient)
{
	if (coefficient <= 0)
	{
		std::cout << "Неверно задан коэффициент масштабирования круга.\n";
	}
	else
	{
		m_rect.height *= coefficient;
		m_rect.width *= coefficient;
	}
}

void Circle::print_coordinates()
{
	std::cout << std::setprecision(4) << "Круг с координатами центра и радиусом:\n"
		<< m_rect.pos.x << " " << m_rect.pos.y << " "
		<< m_rect.height / 2 << '\n';
}
