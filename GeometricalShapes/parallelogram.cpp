#include "parallelogram.h"

using namespace prohorcev;

Parallelogram::Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3)
{

}

double Parallelogram::getArea()
{
	return 0.0;
}

rectangle_t Parallelogram::getFrameRect()
{
	return m_rect;
}

void Parallelogram::move(point_t pos)
{
	m_rect.pos = pos;
}

void Parallelogram::move(double offset_x, double offset_y)
{
	m_rect.pos.x += offset_x;
	m_rect.pos.y += offset_y;
}

void Parallelogram::scale(double coefficient)
{
}

void Parallelogram::print_coordinates()
{
}
