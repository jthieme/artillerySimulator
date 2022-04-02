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
#include <iterator>
#include <list>
#include <vector>
using namespace std;
using namespace std;

class Bullet
{
private:
	bool isFlying = false;
	const double muzzleVelocity = 827.0;
	const double mass = 46.7;
	const double radius = 0.077445;
	double time = 0.0;
	double age = 0.0;
	double altitude;
	double density;
	double timeInterval = 0.5;
	Direction direction;
	list<Position> path;
	Position pos;
	Velocity velocity;

public:
	Bullet() 
	{
		setPath();
	};

	void setDirection(double angle){ direction.setRadians(angle); }
	void setIsFlying(bool isFlying) { this->isFlying = isFlying; }
	bool getIsFlying() { return isFlying; }
	void fire(double angle, Position& position);
	void draw(ogstream& gout);
	void drawFlight(ogstream& gout);
	Position getPosition(){ return pos; }
	double getSpeed() { return velocity.getSpeed(); }
	double getRadius() { return radius; }
	void advance();
	void reset(Position pos) { setPosition(pos); };
	void setPosition(Position& position);
	void bulletCollide() { setIsFlying(false); }
	
	void setPath()
	{   
		path.clear();
		path.push_back(pos); 
	}
	

};


