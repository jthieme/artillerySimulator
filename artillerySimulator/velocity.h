/***************************************************************
 * Header File:
 *    Velocity : Represents the velocity in the artillery simulation
 * Author:
 *    Josh Thieme, Lakeram Narine
 * Summary:
 *    Everything about the velocity
 ***************************************************************/

#pragma once
#include "direction.h" // for DIRECTION

 /***********************************************************************
 * VELOCITY
 * This will help in allowing the objects to move
 ************************************************************************/
class Velocity
{
public:
	// constructors for velosity, setting our intital dx and dy
	Velocity() : dx(0.0), dy(0.0) {}
	Velocity(double dx, double dy) : dx(dx), dy(dy) {}
	Velocity(double speed, Direction& direction) { setSpeedAngle(speed, direction); }
	
	/***********************************************************************
   * OPERATOR =
   * This will assign our dx / dy to the right hand side (rhs)
   ************************************************************************/
	Velocity& operator =(const Velocity& rhs)
	{
		dx = rhs.dx;
		dy = rhs.dy;
		return *this;
	}
	
	/***********************************************************************
   * GET DX / DY
   * This will return the dx / dy
   ************************************************************************/
	double getDX() { return dx; };
	double getDY() { return dy; };

	/***********************************************************************
   * SET DX / DY
   * This will set the dx / dy
   ************************************************************************/
	void setDX(double dx) { this->dx = dx; };
	void setDY(double dy) { this->dy = dy; };

   /***********************************************************************
   * SET SPEED ANGLE
   * This will set the speed depending on the current direction (angle)
   ************************************************************************/
	void setSpeedAngle(double speed, Direction& direction);

	/***********************************************************************
   * ADD DX / DY
   * This will add our new velocity to current velosity
   ************************************************************************/
	void addDX(double dx) { setDX(getDX() + dx); };
	void addDY(double dy) { setDY(getDY() + dy); };

	/***********************************************************************
   * SET DX / DY
   * This will set our new velocity to current velosity
   ************************************************************************/
	void setDxDy(double dx, double dy) { this->dx = dx; this->dy = dy; }

	/***********************************************************************
   * ADD VELOCITY (V)
   * This will add velocity to our chaning position (dx / dy)
   ************************************************************************/
	void addV(const Velocity& velocity)
	{
		dx += velocity.dx;
		dy += velocity.dy;
	}

	/***********************************************************************
   * OPERATOR =
   * This will assign our velocity to the right hand side (rhs)
   ************************************************************************/
	Velocity& operator += (const Velocity& rhs)
	{
		addV(rhs);
		return *this;
	}

	/***********************************************************************
   * REVERSE
   * This will reverse our dx / dy
   ************************************************************************/
	void reverse()
	{
		dx *= -1.0;
		dy *= -1.0;
	}
	
	/***********************************************************************
   * GET SPEED
   * This will find our speed using the formula:
	*    a^2 + b^2 = c^2
	* We will use it as such:
	*    c^2 = a^2 +b^2
	* Or in other words:
	*    sqrt(speed) = dx^2 + dy^2
   ************************************************************************/
	double getSpeed() { return sqrtl(this->dx * this->dx + this->dy * this->dy); };

private:
	double dx;
	double dy;
};

/***********************************************************************
* SET SPEED ANGLE
* This will set our speed according to its current direction (angle)
************************************************************************/
void Velocity::setSpeedAngle(double speed, Direction& direction)
{
	setDX(speed * direction.getDx());
	setDY(speed * direction.getDy());
}