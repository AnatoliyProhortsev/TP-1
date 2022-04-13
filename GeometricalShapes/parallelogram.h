#pragma once

#include <iostream>
#include "shape.h"

namespace prohorcev
{
	class Parallelogram : public Shape
	{
	private:
		rectangle_t m_rect;
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


