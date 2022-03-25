#pragma once
#include "direction2.h"
class Velocity
{
public:
	// constructors for velosity, setting our 
	//intital dx and dy
	Velocity() : dx(0.0), dy(0.0) {}
	Velocity(double dx, double dy) : dx(dx), dy(dy) {}
	Velocity(double speed, Direction& direction) { setSpeedAngle(speed, direction); }
	Velocity& operator =(const Velocity& rhs)
	{
		dx = rhs.dx;
		dy = rhs.dy;
		return *this;
	}

	double getDX() { return dx; };
	double getDY() { return dy; };

	void setDX(double dx) { this->dx = dx; };
	void setDY(double dy) { this->dy = dy; };
	void setSpeedAngle(double speed, Direction& direction);
	//adds our new velocity to current velosity
	void addDX(double dx) { setDX(getDX() + dx); };
	void addDY(double dy) { setDY(getDY() + dy); };
	void setDxDy(double dx, double dy) { this->dx = dx; this->dy = dy; }

	void addV(const Velocity& velocity)
	{
		dx += velocity.dx;
		dy += velocity.dy;
	}
	Velocity& operator += (const Velocity& rhs)
	{
		addV(rhs);
		return *this;
	}
	void reverse()
	{
		dx *= -1.0;
		dy *= -1.0;
	}
	// calculte the Speed of the Lander, this will be need in the Display in the Game class.
	double getSpeed() { return sqrtl(this->dx * this->dx + this->dy * this->dy); };


private:
	double dx;
	double dy;
};

void Velocity::setSpeedAngle(double speed, Direction& direction)
{
	setDX(speed * direction.getDx());
	setDY(speed * direction.getDy());

}