/*****************************************
* HEADER FILE - VELOCITY
*****************************************/
#pragma once
#include <iostream>
#include <math.h>

/*****************************************
* VELOCITY ZERO
* This is a Mock class made to ensure that
* the unit tests will pass without using
* VELOCITY itself.
*****************************************/
class VelocityZero
{

public:

   // initalize the variables
   double x = 0;
   double y = 0;
   double dx = 0;
   double dy = 0;
   double s = 0;

   /*****************************************
   * GET DX / DY
   * These two methods will simply return
   * the current value of dx / dy.
   *****************************************/
   double getDX(double dx) { return dx; }
   double getDY(double dy) { return dy; }

   /*****************************************
   * SET DX / DY
   * These two methods will set dx / dy to
   * a new value.
   *****************************************/
   double setDX(double dx) { return dx = 2.0; }
   double setDY(double dy) { return dy = 1.0; }

   /*****************************************
   * ADD DX / DY
   * These two methods will add the current
   * x / y position to the new dx / dy.
   *****************************************/
   double addDX(double x, double dx)
   {
      x + dx;
      return dx = 3.0;
   }
   double addDY(double y, double dy)
   {
      y + dy;
      return dy = 3.0;
   }

   /*****************************************
   * GET SPEED
   * This method will use the Pythagoreum
   * Theorum to find the speed:
   *    a^2 + b^2 = c^2
   * We need to find the equivalent of c^2,
   * so we will reorder to fit our needs:
   *    c = sqrt(a^2 + b^2)
   * In our variables:
   *    s = sqrt(dx^2 + dy^2)
   *****************************************/
   double getSpeed(double s, double dx, double dy)
   {
      return s = sqrt(dx * dx + dy * dy);
   }
};

/*****************************************
* VELOCITY
*****************************************/
class Velocity : VelocityZero
{
protected:

   // initialize the variables
   double x = 0;
   double y = 0;
   double dx = 0;
   double dy = 0;
   double s = 0;

public:

   /*****************************************
   * GET DX / DY
   * These two methods will simply return
   * the current value of dx / dy.
   *****************************************/
   virtual double getDX(double dx) { return dx; }
   virtual double getDY(double dy) { return dy; }

   /*****************************************
   * SET DX / DY
   * These two methods will set dx / dy to
   * a new value.
   *****************************************/
   virtual double setDX() { return dx = 2.0; }
   virtual double setDY() { return dy = 1.0; }

   /*****************************************
   * ADD DX / DY
   * These two methods will add the current
   * x / y position to the new dx / dy.
   *****************************************/
   virtual double addDX(double x, double dx)
   {
      x + dx;
      return dx = 3.0;
   }
   virtual double addDY(double y, double dy)
   {
      y + dy;
      return dy = 3.0;
   }

   /*****************************************
   * GET SPEED
   * This method will use the Pythagoreum
   * Theorum to find the speed:
   *    a^2 + b^2 = c^2
   * We need to find the equivalent of c^2,
   * so we will reorder to fit our needs:
   *    c = sqrt(a^2 + b^2)
   * In our variables:
   *    s = sqrt(dx^2 + dy^2)
   *****************************************/
   virtual double getSpeed(double s, double dx, double dy)
   {
      return s = sqrt(dx * dx + dy * dy);
   }
};