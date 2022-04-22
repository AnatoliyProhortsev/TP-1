#include "parallelogram.h"

using namespace prohorcev;

bool is_valid_triangle(const point_t& p1, const point_t& p2, const point_t& p3)
{
	double a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.x) * (p1.y - p2.y)),
		b = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y)),
		c = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));

	return (a + b > c && a + c > b && b + c > a);
}

Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3)
{
	if( p1.x != p2.x && !is_valid_triangle(p1,p2,p3))
		throw std::invalid_argument("Неверно задан треугольник, образующий параллелограмм.");
	else
	{	
		m_p1.x = p1.x;
		m_p1.y = p1.y;
		m_p2.x = p2.x;
		m_p2.y = p2.y;
		m_p3.x = p3.x;
		m_p3.y = p3.y;
		m_rect.width = abs(m_p1.x - m_p2.x) + abs(m_p1.x - m_p3.x);
		m_rect.height = abs(m_p3.y - m_p1.y);
		m_rect.pos.x = (m_p3.x + m_p2.x) / 2;
		m_rect.pos.y = (m_p3.y + m_p2.y) / 2;
	}
}

double Parallelogram::getArea() const
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

rectangle_t Parallelogram::getFrameRect() const
{
	std::cout << "Ограничивающий прямоугольник с координатами:\n"
		<< m_rect.pos.x - m_rect.width / 2 << " " << m_rect.pos.y - m_rect.height / 2 << " "
		<< m_rect.pos.x + m_rect.width / 2 << " " << m_rect.pos.y + m_rect.height / 2 << '\n';

	return m_rect;
}

void Parallelogram::move(const point_t& pos)
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
		std::cout << "Невозможно масшатбировать параллелограмм с заданным коэффициентом.\n";
	else
	{
		m_p1.x = (m_p1.x - m_rect.pos.x) * coefficient + m_rect.pos.x;
		m_p2.x = (m_p2.x - m_rect.pos.x) * coefficient + m_rect.pos.x;
		m_p3.x = (m_p3.x - m_rect.pos.x) * coefficient + m_rect.pos.x;

		m_p1.y = (m_p1.y - m_rect.pos.y) * coefficient + m_rect.pos.y;
		m_p2.y = (m_p2.y - m_rect.pos.y) * coefficient + m_rect.pos.y;
		m_p3.y = (m_p3.y - m_rect.pos.y) * coefficient + m_rect.pos.y;

		m_rect.width = abs(m_p1.x - m_p2.x) + abs(m_p1.x - m_p3.x);
		m_rect.height = abs(m_p3.y - m_p1.y);
		m_rect.pos.x = (m_p3.x + m_p2.x) / 2;
		m_rect.pos.y = (m_p3.y + m_p2.y) / 2;
	}
}

void Parallelogram::print_coordinates() const
{
	std::cout << "Параллелограмм с координатами образующего треугольника:\n"
		<< m_p1.x << ' ' << m_p1.y << ' '<< m_p2.x << ' ' << m_p2.y << ' ' << m_p3.x << ' ' << m_p3.y << '\n';
}
