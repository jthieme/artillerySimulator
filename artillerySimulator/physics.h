/***************************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine, Br. Helfrich
* Assignment:
*    W10 - Artillery Tests Pass
* Description:
*    This will have the functions in order for all of the 
     physics to work properly.
*    Notice that this is NOT a class because it is simply a 
     collection of functions that are not necessarily related
	  to each other. Classes represent nouns and Physics is not
	  a descriptor of an object. Rather, it is a series of laws
	  that objects behave from.
* How long did this take?
*    About 3hrs
***************************************************************/

#pragma once
#include <math.h>
#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif
#include <cmath>
#include <iostream>
#include <cassert>
#include "velocity.h"

using namespace std;

/****************************************************************
* MAPPING
* This struct will allow us to a domain and a range
*****************************************************************/
struct Mapping
{
	double domain;
	double range;
};

double areaFromRadius(double radius);
double forceFromDrag(double density, double drag, double radius, double velocity);
double accelerationFromForce(double force, double mass);
double velocityFromAcceleration(double accceleration, double time);
double linearInterpolation(double d0, double r0, double d1, double r1, double d);
double linearInterpolation(const Mapping mapping[], int numMapping, double domain);
double linearInterpolation(const Mapping m0, const Mapping m1, double d);
double gravityFromAltitude(double altitude);
double speedOfSoundFromAltitude(double altitude);
double densityFromAltitude(double altitude);
double machFromSpeed(double speed, double altitude);
double dragFromSpeed(double speed, double altitude);

/***************************************************************
* AREA FROM RADIUS
* Calculate the area of the bullet
***************************************************************/
double areaFromRadius(double radius)
{
	return M_PI * (radius * radius);
}

/**************************************************************
* FORCE FROM DRAG
* Calculate the Force using the formula:
*    force = 1/2 * density * drag * area * velocity * velosity
***************************************************************/
double forceFromDrag(double density, double drag, double radius, double velocity)
{
	double area = areaFromRadius(radius);

	return 0.5 * density * drag * area * velocity * velocity;
}

/**************************************************************
* ACCELERATION FROM FORCE
* Calculate the accelration from force applied
***************************************************************/
double accelerationFromForce(double force, double mass)
{
	return force / mass;
}

/***************************************************************
* VELOCITY FROM ACCELERATION
* Calculate the Velosity due to acceleration
***************************************************************/
double velocityFromAcceleration(double accceleration, double time)
{
	return accceleration * time;
}

/***************************************************************
* GRAVITY FROM ALTITUDE
* Using the intrpolation we will find the appriopriate gravity
* from different altitudes
***************************************************************/
double gravityFromAltitude(double altitude)
{
	const Mapping gravityMapping[] =
	{
		// altitude      gravity
		{ 0.0	  ,   9.807},
		{ 1000.0,   9.804},
		{ 2000.0,   9.801},
		{ 4000.0,   9.794},
		{ 5000.0,   9.791},
		{ 6000.0,   9.788},
		{ 7000.0,   9.785},
		{ 8000.0,   9.782},
		{ 9000.0,   9.779},
		{10000.0,	9.776},
		{15000.0,   9.761},
		{20000.0,	9.745},
		{25000.0,   9.730}
	};

	// interpolate gravity since it's not constant
	double gravity = linearInterpolation(gravityMapping, sizeof(gravityMapping) / sizeof(gravityMapping[0]), altitude);

	// return what we find
	return gravity;
}

/***************************************************************
* DENSITY FROM ALTITUDE
* Using the intrpolation we will find the appriopriate density
* from different altitudes
***************************************************************/
double densityFromAltitude(double altitude)
{
	const Mapping densityMapping[] =
	{
		// altitude      density
		{0,	1.2250000},
		{1000,	1.1120000 },
		{2000,	1.0070000},
		{3000,	0.9093000},
		{4000,	0.8194000},
		{5000,	0.7364000},
		{6000,	0.6601000},
		{7000,	0.5900000},
		{8000,	0.5258000},
		{9000,	0.4671000},
		{10000,	0.4135000},
		{15000, 0.1948000},
		{20000,	0.0889100},
		{25000,	0.0400800},
		{30000,	0.0184100},
		{40000,	0.0039960},
		{50000,	0.0010270},
		{60000,	0.0003097},
		{70000,	0.0000828},
		{80000,	0.0000185}
	};

	// interpolate the air density since it's not a constant
	double density = linearInterpolation(densityMapping, sizeof(densityMapping) / sizeof(densityMapping[0]), altitude);

	// return what we find
	return density;
}

/***************************************************************
* SPEED OF SOUND FROM ALTITUDE
* Using the intrpolation we will find the appriopriate speed
* of sound from different altitude
***************************************************************/
double speedOfSoundFromAltitude(double altitude)
{
	const Mapping speedOfSoundMapping[] =
	{
   // altitude  speedOfSound
	{0,	   340},
	{1000,   336},
	{2000,	332},
	{3000,	328},
	{5000,	320},
	{6000,	316},
	{7000,	312},
	{8000,	308},
	{9000,	303},
	{10000,	299},
	{15000,	295},
	{20000,	295},
	{25000,	295},
	{30000,	305},
	{40000,	324}

	};

	// interpolate the speed of sound
	double speedOfSound = linearInterpolation(speedOfSoundMapping, sizeof(speedOfSoundMapping) / sizeof(speedOfSoundMapping[0]), altitude);

	// return what we find
	return speedOfSound;
}


/***************************************************************
* LINEAR INTERPOLATION
* This function will loop through our maps and find our 
* intropolation for a specific value given four points
***************************************************************/
double linearInterpolation(const Mapping mapping2[], int numMapping, double domain)
{
	if (domain < mapping2[0].domain)
		return mapping2[0].range;

	for (int i = 0; i < numMapping - 1; i++)
	{
		if (mapping2[i + 0].domain <= domain && domain <= mapping2[i + 1].domain)
			return linearInterpolation(mapping2[i + 0], mapping2[i + 1], domain);
	}

	return mapping2[numMapping - 1].range;
}

/***************************************************************
* LINEAR INTERPOLATION
* This func will loop through our maps and find the our
* intropolation for a specific value given four points
****************************************************************/
double linearInterpolation(Mapping m0, Mapping m1, double d)
{
	return linearInterpolation(m0.domain, m0.range, m1.domain, m1.range, d);
}

/***************************************************************
* LINEAR INTERPOLATION
* This func will loop through our maps and find the our
* intropolation for a specific value given four points
****************************************************************/
double linearInterpolation(double d0, double r0, double d1, double r1, double d)
{
	assert(abs(d1 - d0) >= abs(d - d0));
	double range = 0;
	if (d1 - d0 == 0)
	{
		// we do this because we cannot divide by 0
		return range = 0;
	}
	range = r0 + (r1 - r0) * ((d - d0) / (d1 - d0));
	return range;
}

/***************************************************************
* DRAG FROM SPEED
* Using linear interpolation, we will find the drag depending
* on our mach (speed) and drag coefficient
****************************************************************/
double dragFromSpeed(double speed, double altitude)
{
	const Mapping dragSpeed[] =
	{
		//Mach	//Drag Coefficient
		 {0.300,	0.1629},
		 {0.500, 0.1659},
		 {0.700,	0.2031},
		 {0.890,	0.2597},
		 {0.920,	0.3010},
		 {0.960,	0.3287},
		 {0.980,	0.4002},
		 {1.000,	0.4258},
		 {1.020,	0.4335},
		 {1.060,	0.4483},
		 {1.240,	0.4064},
		 {1.530,	0.3663},
		 {1.990,	0.2897},
		 {2.870,	0.2297},
		 {2.890,	0.2306},
		 {5.000,	0.2656}
	};

	// set the mach depending on the current speed and altitude
	double mach = machFromSpeed(speed, altitude);

	// interpolate the drag
	double drag = linearInterpolation(dragSpeed, sizeof(dragSpeed) / sizeof(dragSpeed[0]), mach);
	
	// return what we find
	return drag;

}

/***************************************************************
* MACH FROM SPEED
* This will find the mach using the formula:
*    mach = speed of object / speed of sound
****************************************************************/
double machFromSpeed(double speed, double altitude)
{
	double speedOfSound = speedOfSoundFromAltitude(altitude);
	
	return speed / speedOfSound;
}
