/***********************************************************************
 * Header File:
 *    Direction : Represents the direction in the artillery simulation
 * Author:
 *    Josh Thieme, Lakeram Narine
 * Summary:
 *    Everything about the direction for the objects
 ************************************************************************/
#pragma once

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "bullet.h"
#include <cmath>
#include <iostream>
#include <iostream>
class Direction
{
private:
	double radians;
	const double PI = 3.1415926;
public:
	Direction() : radians(0.0) {};
	Direction(double degrees) : radians(0.0) { radians = radiansFromDegrees(degrees); };
	void setRadians(double radian) { radians = radian; };
	void setDegree(double degree) { radians = radiansFromDegrees(degree); }
	void setDYDX(double dx, double dy) { radians = atan2(dx, dy); };

	double getRadians() { return radians; };
	double getDx() { return sin(radians); };
	double getDy() { return cos(radians); };
	double radiansFromDegrees(double degree) { return degree * (PI / 180); }

	double getDegrees() { return radians * 180 / PI; };
};