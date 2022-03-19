/******************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine
* Assignment:
*    W10 - Artillery Tests Pass
* Description:
*    This will have the unit tests pass with the correct
*    code written.
* How long did this take?
*    About 30 minutes
*******************************************************/
#pragma once
#include <iostream>
#include <cassert>

// include program code to get the test cases working
#include "Velocity.h"

/******************************************************
* TEST VELOCITY
* This class is a Unit Test to ensure that the Velocity
* class is thoroughly tested to ensure it functions
* properly.
*******************************************************/
class TestVelocity
{
public:

   /******************************************************
   * RUN
   * When TestVelocity::run() is called, it will perform
   * the following tests.
   *******************************************************/
   void run()
   {
      testGetDX();
      testGetDY();
      testSetDX();
      testSetDY();
      testAddDX();
      testAddDY();
      testGetSpeed();
   }

private:

   /******************************************************
   * TEST GET DX / DY
   * Velocity::getDX() / getDY() return the current
   * dx / dy position
   *******************************************************/
   void testGetDX()
   {
      // SETUP
      VelocityZero vz;
      vz.dx = 0;
      // EXERCISE
      vz.dx = vz.getDX(vz.dx);
      // VERIFY
      assert(vz.dx == 0);
      // TEARDOWN
   }

   void testGetDY()
   {
      // SETUP
      VelocityZero vz;
      vz.dy = 0;
      // EXERCISE
      vz.dy = vz.setDY(vz.dy);
      // VERIFY
      assert(vz.dy == 1);
      // TEARDOWN
   }

   /******************************************************
   * TEST SET DX / DY
   * Velocity::setDX() / setDY() need to set the dx / dy
   * member variables to their current position.
   *******************************************************/
   void testSetDX()
   {
      // SETUP
      VelocityZero vz;
      vz.dx = 0;
      // EXERCISE
      vz.dx = vz.setDX(vz.dx);
      // VERIFY
      assert(vz.dx == 2);
      // TEARDOWN
   }

   void testSetDY()
   {
      // SETUP
      VelocityZero vz;
      vz.dy = 0;
      // EXERCISE
      vz.dy = vz.setDY(vz.dy);
      // VERIFY
      assert(vz.dy == 1);
      // TEARDOWN
   }

   /******************************************************
   * TEST ADD DX / DY
   * Velocity::addDX() / addDY() need to add the previous
   * previous x / y position to the new dx / dy position.
   *******************************************************/
   void testAddDX()
   {
      // SETUP
      VelocityZero vz;
      vz.x = 1;
      vz.dx = 2;
      // EXERCISE
      vz.dx = vz.addDX(vz.x, vz.dx);
      // VERIFY
      assert(vz.x == 1);
      assert(vz.dx == 3);
      // TEARDOWN
   }

   void testAddDY()
   {
      // SETUP
      VelocityZero vz;
      vz.y = 1;
      vz.dy = 2;
      // EXERCISE
      vz.dy = vz.addDY(vz.y, vz.dy);
      // VERIFY
      assert(vz.y == 1);
      assert(vz.dy == 3);
      // TEARDOWN
   }

   /******************************************************
   * TEST GET SPEED
   * Velocity::getSpeed() needs to return sqrt(dx^2 + dy^2)
   *******************************************************/
   void testGetSpeed()
   {
      // SETUP
      VelocityZero vz;
      // EXERCISE
      vz.dx = 3;
      vz.dy = 4;
      vz.s = vz.getSpeed(vz.s, vz.dx, vz.dy);
      // VERIFY
      assert(vz.dx == 3);
      assert(vz.dy == 4);
      assert(vz.s == 5);
      // TEARDOWN
   }
};