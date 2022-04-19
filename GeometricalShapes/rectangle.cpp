#include "rectangle.h"

using namespace prohorcev;

Rectangle::Rectangle(double x_lower_left, double y_lower_left, double x_upper_right, double y_upper_right)
{
	if (x_lower_left >= x_upper_right || y_lower_left >= y_upper_right)
	{
		std::cout << "Неверные параметры прямоугольника. Создание прямоугольника с точками (0, 0, 0, 0)\n";
		m_rect.height = 0;
		m_rect.width = 0;
		m_rect.pos.x = 0;
		m_rect.pos.y = 0;
	}
	else
	{
		m_rect.height = y_upper_right - y_lower_left;
		m_rect.width = x_upper_right - x_lower_left;
		m_rect.pos.x = (x_upper_right + x_lower_left) / 2;
		m_rect.pos.y = (y_upper_right + y_lower_left) / 2;
	}
}

double Rectangle::getArea()
{
	return m_rect.height * m_rect.width;
}

rectangle_t Rectangle::getFrameRect()
{
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
	std::cout <<std::setprecision(4)<< "Прямоугольник с координатами:\n" 
												   << double(m_rect.pos.x - m_rect.width / 2) << " " << double(m_rect.pos.y - m_rect.height / 2) << " "
												   << double(m_rect.pos.x + m_rect.width / 2) << " " << double(m_rect.pos.y + m_rect.height / 2) << '\n';
}
