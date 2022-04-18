#include "parallelogram.h"

using namespace prohorcev;

bool is_valid_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)),
		b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3)),
		c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

	return (a + b > c && a + c > b && b + c > a);
}

Parallelogram::Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3)
{
	if( x1 != x2 && !is_valid_triangle(x1, y1, x2, y2, x3, y3))
	{
		std::cout << "Неверно задан треугольник, образующий параллелограмм. Создание параллелограмма, с точками образующего треугольника (0,0,0,0,0,0)\n";
		m_p1.x = 0;
		m_p1.y = 0;
		m_p2.x = 0;
		m_p2.y = 0;
		m_p3.x = 0;
		m_p3.y = 0;
		m_rect.height = 0;
		m_rect.width = 0;
		m_rect.pos.x = 0;
		m_rect.pos.y = 0;
	}
	else
	{	
		m_p1.x = x1;
		m_p1.y = y1;
		m_p2.x = x2;
		m_p2.y = y2;
		m_p3.x = x3;
		m_p3.y = y3;
		m_rect.width = m_p2.x - m_p3.x + m_p2.x - m_p1.x;
		m_rect.height = abs(m_p1.y - m_p3.y);
		m_rect.pos.x = m_rect.width / 2;
		m_rect.pos.x = m_rect.height / 2;
	}
}

double Parallelogram::getArea()
{
	point_t a, b;
	double a_len, b_len;

	if (m_p3.y > m_p1.y)
	{
		a.x = m_p3.x - m_p1.x;
		a.y = m_p3.y - m_p1.y;

		b.x = m_p2.x - m_p1.x;
		b.y = m_p2.y - m_p1.y;
	}
	else
	{
		a.x = m_p3.x - m_p2.x;
		a.y = m_p3.y - m_p2.y;

		b.x = m_p1.x - m_p2.x;
		b.y = m_p1.y - m_p2.y;
	}
	a_len = sqrt(a.x * a.x + a.y * a.y);
	b_len = sqrt(b.x * b.x + b.y * b.y);
	double cos_phi = (a.x * b.x + a.y * b.y) / a_len / b_len; //Косинус угла между двумя сторонами
	return a_len * b_len * sqrt(1 - cos_phi * cos_phi);
}

rectangle_t Parallelogram::getFrameRect()
{
	return m_rect;
}

void Parallelogram::move(point_t pos)
{
	double offset_x = pos.x - m_rect.pos.x,
		   offset_y = pos.y - m_rect.pos.y;
	m_rect.pos = pos;
	m_p1.x += offset_x;
	m_p1.y += offset_y;
	m_p2.x += offset_x;
	m_p2.y += offset_y;
	m_p3.x += offset_x;
	m_p3.y += offset_y;
}

void Parallelogram::move(double offset_x, double offset_y)
{
	m_rect.pos.x += offset_x;
	m_rect.pos.y += offset_y;
	m_p1.x += offset_x;
	m_p1.y += offset_y;
	m_p2.x += offset_x;
	m_p2.y += offset_y;
	m_p3.x += offset_x;
	m_p3.y += offset_y;
}

void Parallelogram::scale(double coefficient)
{
	if (coefficient <= 0)
		std::cout << "Невозможно масшатбировать прямоугольник с заданным коэффициентом.\n";
	else
	{
		std::cout << "scale\n";
	}
}

void Parallelogram::print_coordinates()
{
	std::cout << std::setprecision(2) << "Параллелограм с координатами образующего треугольника\n"
		<< m_p1.x << ' ' << m_p1.y << ' '<< m_p2.x << ' ' << m_p2.y << ' ' << m_p3.x << ' ' << m_p3.y << '\n';
}
