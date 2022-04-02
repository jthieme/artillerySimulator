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
#include "bullet.h"     // for BULLET
#include <iostream>     // for input / output

/****************************************************************
* DIRECTION
* This class will allow us to adjust the angle of the Howitzer
*****************************************************************/
class Direction
{
private:
	double radians;
	const double PI = 3.1415926;
public:

	// default constructor sets the Howitzer pointing up
	Direction() : radians(0.0) {};

	// non-default constructor adjusts the angle which is provided by the user
	Direction(double degrees) : radians(0.0) { radians = radiansFromDegrees(degrees); };

	/****************************************************************
	* SET RADIANS
	* This will set the radians
	*****************************************************************/
	void setRadians(double radian) { radians = radian; };

	/****************************************************************
	* SET DEGREES
	* This will set the degrees
	*****************************************************************/
	void setDegree(double degree) { radians = radiansFromDegrees(degree); }

	/****************************************************************
	* SET DX DY
	* This will allow for an object to change position
	*****************************************************************/
	void setDYDX(double dx, double dy) { radians = atan2(dx, dy); };

	/****************************************************************
	* GET RADIANS
	* This will return the radians
	*****************************************************************/
	double getRadians() { return radians; };

	/****************************************************************
	* GET DX
	* This will return the sin of radians, being the dx
	*****************************************************************/
	double getDx() { return sin(radians); };

	/****************************************************************
	* GET DY
	* This will return the cos of radians, being the dy
	*****************************************************************/
	double getDy() { return cos(radians); };

	/****************************************************************
	* RADIANS FROM DEGREES
	* This will convert radians from degrees using the formula:
	*    radians = degree * (3.14 / 180)
	*****************************************************************/
	double radiansFromDegrees(double degree) { return degree * (PI / 180); }

	/****************************************************************
	* GET DEGREES
	* This will return degrees from radians using the formula:
	*    degrees = radians * 180 / 3.14
	*****************************************************************/
	double getDegrees() { return radians * 180 / PI; };
};