#include "bullet.h"



void Bullet::advance()
{
	if (isFlying) {

		path.push_back(b_position);
		
		/*flightPos.setPixelsX(b_position.getPixelsX());
		flightPos.setPixelsY(b_position.getPixelsY());*/
		
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
		

		/*path.pop_front();*/

	}

}

void Bullet::setPosition(Position& position)
{
	b_position.setPixelsX(position.getPixelsX());
	b_position.setPixelsY(position.getPixelsY());
}

void Bullet::fire(double angle, Position& position)
{
	setIsFlying(true);
	setDirection(angle);
	setPosition(position);
	velocity.setSpeedAngle(muzzel_velocity, direction);

}

