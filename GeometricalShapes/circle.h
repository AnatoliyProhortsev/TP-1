#pragma once

#include "shape.h"
#include <iostream>
#include <iomanip>

namespace prohorcev
{
	class Circle: public Shape
	{
	private:
		rectangle_t m_rect;
	public:
		Circle(point_t center, double radius);
		double getArea();
		rectangle_t getFrameRect();
		void move(point_t pos);
		void move(double offset_x, double offset_y);
		void scale(double coefficient);
		void print_coordinates();
	};
}