/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "bullet.h"
#include "direction.h"



using namespace std;

class Howitzer
{
private:
	Position hposition;
	double angle;


public:

	Howitzer() :angle(0.0) {
		hposition.setPixelsX(200.0);
		updateAngle(angle);
	}

	void draw(ogstream& gout, double flighttime)
	{

		gout.drawHowitzer(hposition, angle, flighttime);

	}
	void setPosition(Position& position)
	{
		hposition.setPixelsX(position.getPixelsX());
		hposition.setPixelsY(position.getPixelsY());
	}

	Position getPosition()
	{
		return hposition;
	}

	void rotate(const Interface* pUI)
	{
		if (pUI->isRight())
			angle += 0.05;
		if (pUI->isLeft())
			angle -= 0.05;
	}

	void raise(const Interface* pUI)
	{
		if (pUI->isUp())
			angle += (angle >= 0 ? -0.003 : 0.003);
		if (pUI->isDown())
			angle += (angle >= 0 ? 0.003 : -0.003);
	}

	double getAngle() { return angle; }

	void updateAngle(double radian)
	{
		angle = (2.0 * 3.14159) * (radian / 360.0);
	}

};


