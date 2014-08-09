/*
 * Color.cpp
 *
 *  Created on: Aug 3, 2014
 *      Author: hearthewarsong
 */

#include "../drivers_all.h"

Color::Color() :r(1.0), g(1.0), b(1.0), alpha(1.0)
{
	// TODO Auto-generated constructor stub

}

Color::~Color()
{
	// TODO Auto-generated destructor stub
}

Color::Color(double r, double g, double b, double alpha) :r(r), g(g), b(b), alpha(alpha)
{
}

Color::Color(int r, int g, int b, int alpha) :r(r / 255.0), g(g / 255.0), b(b / 255.0), alpha(alpha / 255.0)
{
}
