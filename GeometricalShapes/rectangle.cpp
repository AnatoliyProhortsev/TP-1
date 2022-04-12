#include "rectangle.h"

using namespace prohorcev;

Rectangle::Rectangle(double x_lower_left, double y_lower_left, double x_upper_right, double y_upper_right): m_rect(0, 0, 0, 0)
{
	if (x_lower_left >= x_upper_right || y_lower_left >= y_upper_right)
	{
		std::cout << "�������� ��������� ��������������. �������� �������������� � ������� (0, 0, 0, 0)\n";
	}
	else
	{
		m_rect = rectangle_t((x_upper_right + x_lower_left) / 2,
							(y_upper_right + y_lower_left) / 2,
							 x_upper_right - x_lower_left, y_upper_right - y_lower_left);
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
		std::cout << "���������� �������������� ������������� � �������� �������������.\n";
	else
	{
		m_rect.height *=coefficient;
		m_rect.width *= coefficient;
	}
}

void Rectangle::print_coordinates()
{
	std::cout <<std::setprecision(2)<< "������������� � ������������:\n" << double(m_rect.pos.x - m_rect.width / 2) << " " << double(m_rect.pos.y - m_rect.height / 2) << " "
												   << double(m_rect.pos.x + m_rect.width / 2) << " " << double(m_rect.pos.y + m_rect.height / 2) << '\n';
}
