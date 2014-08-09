/*
 * SfmlConverter.cpp
 *
 *  Created on: Aug 3, 2014
 *      Author: hearthewarsong
 */

#include "../drivers_all.h"

SfmlConverter::SfmlConverter()
{
	// TODO Auto-generated constructor stub

}

SfmlConverter::~SfmlConverter()
{
	// TODO Auto-generated destructor stub
}

sf::Color SfmlConverter::GetSFColor(const Color& color)
{
	return sf::Color(color.R(),color.G(),color.B(),color.Alpha());
}
