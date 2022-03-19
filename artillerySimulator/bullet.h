/******************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine
* Assignment:
*    W09 - Unit Tests
* Description:
*    This is our Bullet class
* How long did this take?
*    About
*******************************************************/
#pragma once
#include <iostream>
#include <cassert>


#include <iostream>
#include "position.h"
#include "ground.h"
#include "velocity.h"
#include <cassert>

/******************************************************
*  Bullet
*
*******************************************************/

class Bullet
{
private:
	string status;

	Position position;
	Velocity velocity;

	int radius;
	int age;
	double area;
	double muzzleVelosity;
	double mass;

public:
	Bullet();
	void reset();
	void fire();
	void advance();
	void draw();
	bool isflying();

	double getAltitude();
	Position getPosition();
	void setPosition();
	double getFlightTime();
	double getFlightdistance();

	double getSpeed();
	double getCurrentTime();

	bool hitTarget();
	bool hitGround();
	bool isHit();
	bool isFired();

	int getAge();
	void setAge();
	void updateAge();




};