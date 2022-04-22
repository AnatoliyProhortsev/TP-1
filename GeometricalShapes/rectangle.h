#pragma once

#include "shape.h"
#include <iostream>
#include <iomanip>

namespace prohorcev
{
	class Rectangle : public Shape
	{
	private:
		rectangle_t m_rect;
	public:
		Rectangle(point_t left_lower, point_t right_upper);
		double getArea();
		rectangle_t getFrameRect();
		void move(point_t pos);
		void move(double offset_x, double offset_y);
		void scale(double coefficient);
		void print_coordinates();
	};
}


