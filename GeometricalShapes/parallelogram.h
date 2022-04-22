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
		point_t m_p1;
		point_t m_p2;
		point_t m_p3;
	public:
		Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3);
		double getArea() const override;
		rectangle_t getFrameRect() const override;
		void move(const point_t& pos) override;
		void move(double offset_x, double offset_y) override;
		void scale(double coefficient) override;
		void print_coordinates() const override;
	};
}


