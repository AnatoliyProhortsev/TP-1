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
		Rectangle(double x_lower_left, double y_lower_left, double x_upper_right, double y_upper_right);
		double getArea();
		rectangle_t getFrameRect();
		void move(point_t pos);
		void move(double offset_x, double offset_y);
		void scale(double coefficient);
		void print_coordinates();
	};
}


