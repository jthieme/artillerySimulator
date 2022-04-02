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

/****************************************************************
* HOWITZER
* This class will allow us to have user interaction with the 
* simulation using the M777 Howitzer
*****************************************************************/
class Howitzer
{
private:
	Position hposition;
	double angle;
public:

	/*************************************************************
	* This is the constructor that will intitialize the member
	* variables
	**************************************************************/
	Howitzer() :angle(0.0) {
		hposition.setPixelsX(200.0);
		updateAngle(angle);
	}

	/*************************************************************
	* This func thats a pos and set it to the Howitzer pos
	*************************************************************/
	void setPosition(Position& position);

	/*************************************************************
	* This func will draw the Howitzer at a certain position
	* and angle everytime it changes it rotation
	*************************************************************/
	void draw(ogstream& gout, double flighttime){ gout.drawHowitzer(hposition, angle, flighttime);}

	
	/*************************************************************
   * This func returns the current position for the Howitzer
   *************************************************************/
	Position getPosition(){return hposition;}

	/*************************************************************
	* These two func handle the rotation and Raise of the first
	* Howitzer
	**************************************************************/
	void rotate(const Interface* pUI);
	void raise(const Interface* pUI);
	
	/*************************************************************
	* These two func handle the rotation and raise of the second
	* Howitzer
	**************************************************************/
	void raise2(const Interface* pUI);
	void rotate2(const Interface* pUI);

	/************************************************************
	* Retuns the Angle that the Howitzer rotates or Raise in
	*************************************************************/
	double getAngle() { return angle; }

	/************************************************************
	* Converts our Angle rotatation and raise every time there
	* is a movement
	*************************************************************/
	void updateAngle(double radian){ angle = (2.0 * 3.14159) * (radian / 360.0);}
};