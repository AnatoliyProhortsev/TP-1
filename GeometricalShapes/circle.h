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
		Circle(const point_t& center, double radius);
		double getArea() const override;
		rectangle_t getFrameRect() const override;
		void move(const point_t& pos) override;
		void move(double offset_x, double offset_y) override;
		void scale(double coefficient) override;
		void print_coordinates() const override;
	};
}