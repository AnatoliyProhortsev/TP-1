#pragma once

#include "base-types.h"

namespace prohorcev
{
	class Shape
	{
	public:
		virtual double getArea() = 0;
		virtual rectangle_t getFrameRect() = 0;
		virtual void move(point_t pos) = 0;
		virtual void move(double offset_x, double offset_y) = 0;
		virtual void scale(double coefficient) = 0;
		virtual void print_coordinates() = 0;
	};
}