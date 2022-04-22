#pragma once

#include <iostream>
#include <iomanip>
#include "shape.h"

#define _USE_MATH_DEFINES
#include <cmath>

namespace prohorcev
{
	class Parallelogram : public Shape
	{
	private:
		rectangle_t m_rect;
		point_t m_p1, m_p2, m_p3;
	public:
		Parallelogram(point_t p1, point_t p2, point_t p3);
		double getArea();
		rectangle_t getFrameRect();
		void move(point_t pos);
		void move(double offset_x, double offset_y);
		void scale(double coefficient);
		void print_coordinates();
	};
}


