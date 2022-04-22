#include "circle.h"

using namespace prohorcev;

Circle::Circle(point_t center, double radius)
{
	if (radius <= 0)
		throw std::invalid_argument("Введён неверный радиус при создании круга.");
	else
	{
		m_rect.pos.x = center.x;
		m_rect.pos.y = center.y;

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
	std::cout << "Ограничивающий прямоугольник с координатами:\n"
		<< m_rect.pos.x - m_rect.width / 2 << " " << m_rect.pos.y - m_rect.height / 2 << " "
		<< m_rect.pos.x + m_rect.width / 2 << " " << m_rect.pos.y + m_rect.height / 2 << '\n';

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
	std::cout << "Круг с координатами центра и радиусом:\n"
		<< m_rect.pos.x << " " << m_rect.pos.y << " "
		<< m_rect.height / 2 << '\n';
}
