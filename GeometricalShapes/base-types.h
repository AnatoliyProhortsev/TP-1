#pragma once

namespace prohorcev
{
	struct point_t
	{
		point_t(double xcoord, double ycoord) : x(xcoord), y(ycoord) {}
		double x, y;
	};

	struct rectangle_t
	{
		rectangle_t(point_t p, double w, double h) : pos(p), width(w), height(h) {}
		rectangle_t(double x, double y, double w, double h) : pos(x, y), width(w), height(h) {}
		double width, height;
		point_t pos;
	};
}