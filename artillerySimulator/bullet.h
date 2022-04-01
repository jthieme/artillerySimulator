/***********************************************************************
 * Header File:
 *    Bullet: Everything about the bullet
 * Author:
 *    Josh Thieme, Lakeram Narine
 * Summary:
 *    This is to have the bullet in the simulation
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include "velocity.h"
#include "uiInteract.h" 
#include "uiDraw.h"  
#include "physics.h"
#include "direction.h"
using namespace std;

class Bullet
{
private:
	const double muzzel_velocity = 827.0;
	const double mass = 46.7;
	const double radius = 0.077445;
	Velocity velocity;
	Position b_position;
	double time = 0.0;
	double age = 0.0;
	bool isFlying = false;
	double altitude;
	double density;
	double timeInterval = 0.5;
	Direction direction;
	

	

public:
	Bullet() {};
	void setDirection(double angle){ direction.setRadians(angle); }
	void setIsFlying(bool isFlying) { this->isFlying = isFlying; }
	bool getIsFlying() { return isFlying; }
	void fire(double angle, Position& position);
	void draw(ogstream& gout){
		gout.drawProjectile(b_position, 0.5);
		drawFlight(gout);
	}

	void drawFlight(ogstream& gout)
	{
		for (int i = 0; i < 20; i++)
		{
			gout.drawProjectile(flightPos[i], 0.5 * (double)i);
		}
		
	}

	Position getPosition(){ return b_position; }
	double getSpeed() { return velocity.getSpeed(); }
	double getRadius() { return radius; }
	void advance();
	void reset();
	void setPosition(Position& position);

	struct FlightPath
	{		
		Position pos;
		Velocity vel;
		double time;
	};
	Position flightPos[20];
};


