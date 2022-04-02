/***********************************************************************
 * Bullet: Everything about the bullet
 * Author:
 *    Josh Thieme, Lakeram Narine
 * Summary:
 *    This is to have the bullet in the simulation
 ************************************************************************/

#include "bullet.h"

/***********************************************************************
* ADVANCE
* This will enable the bullets to "fly" on the screen
************************************************************************/
void Bullet::advance()
{
	if (isFlying) {
		path.push_back(pos);	
		// get the altitude
		altitude = pos.getMetersY();

		// get speed
		double speed = getSpeed();

		// Modify the Velocity to handle wind Resistnace
		double density = densityFromAltitude(altitude);
		double dragCoefficient = dragFromSpeed(speed, altitude);
		double windResistance = forceFromDrag(density, dragCoefficient, radius, speed);
		double accelerationDrag = accelerationFromForce(windResistance, mass);
		Velocity velocitywind(velocityFromAcceleration(accelerationDrag, timeInterval), direction);

		velocitywind.reverse();
		velocity += velocitywind;

		////Modify velocity to handle gravity
		double accelrationGravity = gravityFromAltitude(altitude);
		double velocityGravity = velocityFromAcceleration(accelrationGravity, timeInterval);

		Velocity velgravity(0, -velocityGravity);
		velocity += (velgravity);

		//Inertia
		pos.addMetersX(velocityFromAcceleration(velocity.getDX(), timeInterval));
		pos.addMetersY(velocityFromAcceleration(velocity.getDY(), timeInterval));
	}
}

/***********************************************************************
 * SET POSITION
 * This will set the bullets starting position at each Howitzer
 ************************************************************************/
void Bullet::setPosition(Position& position)
{
	pos.setPixelsX(position.getPixelsX());
	pos.setPixelsY(position.getPixelsY());
}

/***********************************************************************
* FIRE
* The bullet will begin to travel when this is called
************************************************************************/
void Bullet::fire(double angle, Position& position)
{
	setIsFlying(true);
	setDirection(angle);
	setPosition(position);
	velocity.setSpeedAngle(muzzleVelocity, direction);
}

/***********************************************************************
 * DRAW
 * This is to draw the bullet on the screen
 ************************************************************************/
void Bullet::draw(ogstream& gout)
{
	gout.drawProjectile(pos, 0.5);
	drawFlight(gout);
}

/***********************************************************************
 * DRAW FLIGHT
 * 
 * This is to draw the trailing effect of the bullet as it flies 
 ************************************************************************/
void Bullet::drawFlight(ogstream& gout)
{
	int counter = 0;
	list<Position>::iterator it;
	if (getIsFlying()) {
		for (it = path.begin(); it != path.end(); it++)
		{
			Position pos(it->getMetersX() - 1, it->getMetersY() - 1);
			if (counter > path.size() - 6)
				gout.drawProjectile(pos, 1.5 * (path.size() - counter));
			counter++;
		}
	}
}

