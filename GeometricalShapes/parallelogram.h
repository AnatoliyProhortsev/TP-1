#pragma once

#include <iostream>
#include <iomanip>
#include "shape.h"

namespace prohorcev
{
	class Parallelogram : public Shape
	{
	private:
		rectangle_t m_rect;
		point_t m_p1, m_p2, m_p3;
	public:
		Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3);
		double getArea();
		rectangle_t getFrameRect();
		void move(point_t pos);
		void move(double offset_x, double offset_y);
		void scale(double coefficient);
		void print_coordinates();
	};
}


