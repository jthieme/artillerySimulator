/***********************************************************************
 * Header File:
 *    Howitzer: Everything about the howitzer M777
 * Author:
 *    Josh Thieme, Lakeram Narine
 * Summary:
 *    This is to have the howitzer in the simulation
 ************************************************************************/


#pragma once

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
<<<<<<< HEAD
#include "bullet.h"
#include "direction.h"
=======
#include "bullet.h"     // for BULLET
#include "direction.h"  // for DIRECTION



>>>>>>> b97230f230fb7af2913f4ee96f2a74711f50a417
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
	void setPosition(Position& position);
	void draw(ogstream& gout, double flighttime){ gout.drawHowitzer(hposition, angle, flighttime);}
	Position getPosition(){return hposition;}

<<<<<<< HEAD
	// First Howitzer Handle
	void rotate(const Interface* pUI);
	void raise(const Interface* pUI);
=======
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
		if (pUI->isRight() || pUI->isR())
			angle += 0.05;
		if (pUI->isLeft() || pUI->isD())
			angle -= 0.05;
	}
	
	void raise(const Interface* pUI)
	{
		if (pUI->isUp() || pUI->isE())
			angle += (angle >= 0 ? -0.003 : 0.003);
		if (pUI->isDown() || pUI->isD())
			angle += (angle >= 0 ? 0.003 : -0.003);
	}
>>>>>>> b97230f230fb7af2913f4ee96f2a74711f50a417

	// second howitzer handle
	void raise2(const Interface* pUI);
	void rotate2(const Interface* pUI);

	double getAngle() { return angle; }
	void updateAngle(double radian){ angle = (2.0 * 3.14159) * (radian / 360.0);}

};

