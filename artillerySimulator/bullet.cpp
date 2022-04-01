#include "bullet.h"



void Bullet::advance()
{
	if (isFlying) {

		for (int i = 0; i < 20; i++)
		{
			flightPos[i].setPixelsX(b_position.getPixelsX() *(double)i);
			flightPos[i].setPixelsY(b_position.getPixelsY() / (double)i);
			/*projectilePath[i].setPixelsX((double)i * 2.0);
			projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);*/
		}
		
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


		
		//flightPos(, );
		/*const FlightPath flight;
		flight.pos(b_position.getMetersX(), b_position.getMetersY());*/
		

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

void Bullet::reset()
{

}