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
	/*Bullet(Position position);*/
	void setPosition(Position& position);
	void setDirection(double angle);
	void getDirection();
	void setIsFlying(bool isFlying) { this->isFlying = isFlying; }
	bool getIsFlying() { return isFlying; }
	void reset();
	void fire(double angle, Position& position);
	void advance();
	void draw(ogstream& gout);

	Position getPosition();
	double getSpeed() { return velocity.getSpeed(); }
	void getAngle(double angle);
	double getRadius() { return radius; }
	//bool hitTarget(Ground posTarget, int bulletWidth);
};

void Bullet::draw(ogstream& gout)
{
	gout.drawProjectile(b_position, 0.5);
}

void Bullet::advance()
{
	if (isFlying) {

		// get the altitude
		altitude = b_position.getMetersY();

		// get speed
		double speed = getSpeed();
		Physics ph;

		// Modify the Velocity to handle wind Resistnace
		double density = ph.densityFromAltitude(altitude);
		double dragCoefficient = ph.dragFromSpeed(speed, altitude);
		double windResistance = ph.forceFromDrag(density, dragCoefficient, radius, speed);
		double accelerationDrag = ph.accelerationFromForce(windResistance, mass);
		Velocity velocitywind(ph.velocityFromAcceleration(accelerationDrag, timeInterval), direction);



		velocitywind.reverse();
		velocity += velocitywind;

		////Modify velocity to handle gravity
		double accelrationGravity = ph.gravityFromAltitude(altitude);
		double velocityGravity = ph.velocityFromAcceleration(accelrationGravity, timeInterval);

		Velocity velgravity(0, -velocityGravity);
		velocity += (velgravity);

		//Inertia
		b_position.addMetersX(ph.velocityFromAcceleration(velocity.getDX(), timeInterval));
		b_position.addMetersY(ph.velocityFromAcceleration(velocity.getDY(), timeInterval));
	}

}

void Bullet::setPosition(Position& position)
{
	b_position.setPixelsX(position.getPixelsX());
	b_position.setPixelsY(position.getPixelsY());
}

void Bullet::getAngle(double angle)
{

}

void Bullet::setDirection(double angle)
{
	direction.setRadians(angle);
}

void Bullet::fire(double angle, Position& position)
{
	setIsFlying(true);
	setDirection(angle);
	setPosition(position);
	velocity.setSpeedAngle(muzzel_velocity, direction);

}

Position Bullet::getPosition()
{
	return b_position;
}

//bool Bullet::hitTarget(Ground posTarget, int bulletWidth)
//{
//	// if the bullets positon is within the position of the target, return true, otherwise return false
//	return bulletWidth == posTarget.getPixelsX() ? true : false;
//}

void Bullet::reset()
{

}
