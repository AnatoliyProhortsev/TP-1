#include "rectangle.h"

using namespace prohorcev;

Rectangle::Rectangle(point_t left_lower, point_t right_upper)
{
	if (left_lower.x >= right_upper.x || left_lower.y >= right_upper.y)
		throw std::invalid_argument("Неверные параметры прямоугольника.");
	else
	{
		m_rect.height = right_upper.y - left_lower.y;
		m_rect.width = right_upper.x - left_lower.x;
		m_rect.pos.x = (right_upper.x + left_lower.x) / 2;
		m_rect.pos.y = (right_upper.y + left_lower.y) / 2;
	}
}

double Rectangle::getArea()
{
	return m_rect.height * m_rect.width;
}

rectangle_t Rectangle::getFrameRect()
{
	std::cout << "Ограничивающий прямоугольник с координатами:\n"
		<< m_rect.pos.x - m_rect.width / 2 << " " << m_rect.pos.y - m_rect.height / 2 << " "
		<< m_rect.pos.x + m_rect.width / 2 << " " << m_rect.pos.y + m_rect.height / 2 << '\n';

	return m_rect;
}

void Rectangle::move(point_t pos)
{
	m_rect.pos = pos;
}

void Rectangle::move(double offset_x, double offset_y)
{
	m_rect.pos.x += offset_x;
	m_rect.pos.y += offset_y;
}

void Rectangle::scale(double coefficient)
{
	if (coefficient <= 0)
		std::cout << "Невозможно масшатбировать прямоугольник с заданным коэффициентом.\n";
	else
	{
		m_rect.height *=coefficient;
		m_rect.width *= coefficient;
	}
}

void Rectangle::print_coordinates()
{
	std::cout << "Прямоугольник с координатами:\n" 
												   << double(m_rect.pos.x - m_rect.width / 2) << " " << double(m_rect.pos.y - m_rect.height / 2) << " "
												   << double(m_rect.pos.x + m_rect.width / 2) << " " << double(m_rect.pos.y + m_rect.height / 2) << '\n';
}
