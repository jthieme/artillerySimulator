/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include "velocity.h"
#include "uiInteract.h" 
#include "uiDraw.h"  
using namespace std;

class Bullet
{
private:
	double mass = 46.7;
	double radius = 0.077445;
	Velocity velocity;
	Position b_position;
	double time = 0.0;
	double age = 0.0;
	string status = "Dead";
	double speed;
	double altitude;
	double density;
public:
	Bullet() {};
	/*Bullet(Position position);*/
	void setPosition(Position& position);

	void getDirection();
	void reset();
	void fire();
	void advance();
	void draw(ogstream& gout);
	bool isFlying();
	double getAltitude();
	Position getPosition();
	double getFlightTime();
	double getFlightDistance();
	double getSpeed();
	double getCurrentTime();
};

void Bullet::draw(ogstream& gout)
{
	gout.drawProjectile(b_position, 0.5);
}

void Bullet::advance()
{
	// get the altitude
	altitude = b_position.getMetersY();

	// get speed
	//speed = velocity.getSpeed();

	// Modify the Vleocity to handle wind Resistnace

	cout << "this is altitude" << altitude << endl;
	// get the direction that the howitzer is pointing at 
	// move my x and y in that direction
	b_position.addPixelsX(0.5);
	b_position.addPixelsY(0.5);
}

void Bullet::setPosition(Position& position)
{
	b_position.setPixelsX(position.getPixelsX());
	b_position.setPixelsY(position.getPixelsY());
}



