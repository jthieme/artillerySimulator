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

#include "bullet.h"     // for BULLET
#include "direction.h"  // for DIRECTION

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

	// First Howitzer Handle
	void rotate(const Interface* pUI);
	void raise(const Interface* pUI);
	// second howitzer handle
	void raise2(const Interface* pUI);
	void rotate2(const Interface* pUI);

	double getAngle() { return angle; }
	void updateAngle(double radian){ angle = (2.0 * 3.14159) * (radian / 360.0);}

};

