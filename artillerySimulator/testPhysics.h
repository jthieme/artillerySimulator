/******************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine, James Helfrich
* Assignment:
*    W10 - Artillery Tests Pass
* Description:
*    This will have the unit tests pass with the correct
*    code written.
* How long did this take?
*    About 30 minutes
*******************************************************/


#pragma once

#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include "physics.h"
#include <cassert>

using namespace std;
/******************************************************
* TEST Physics
* This class is a Unit Test to ensure that the Physics
* class is thoroughly tested to ensure it functions
* properly.
*******************************************************/
class TestPhysics
{
public:
   void run()
   {
      /******************************************************
      * RUN
      * When TestPhysics::run() is called, it will perform
      * the following tests.
      *******************************************************/
      test_areaFromRadius();
      test_forceFromDrag();
      test_accelerationFromForce();
      test_velocityFromAcceleration();
      test_linearInterpolation();
      test_gravityFromAltitude();
      test_densityFromAltitude();
      test_speedOfSoundFromAltitude();
   }

   /******************************************************
   * TEST areaFromRadius() to get the area of the bullet
   *******************************************************/
   void test_areaFromRadius() const
   {
      //setup
      Physics ph;
      //exercise
      //verify
      assert(0.0 == ph.areaFromRadius(0.0));
      assert(ph.M_PI == ph.areaFromRadius(1.0));
      assert(ph.M_PI * 4.0 == ph.areaFromRadius(2.0));
      cout << "Pass Radius" << endl;
   }
   /******************************************************
   * TEST forceFromDrag() to get the correct drag when
   * calculated
   *******************************************************/
   void test_forceFromDrag() const
   {
      //setup
      Physics ph;
      //exercise
      //verify
      assert(0.0 == ph.forceFromDrag(1.0, 1.0, 1.0, 0.0));
      assert(0.0 == ph.forceFromDrag(1.0, 1.0, 0.0, 1.0));
      assert(0.0 == ph.forceFromDrag(1.0, 0.0, 1.0, 1.0));
      assert(0.0 == ph.forceFromDrag(0.0, 1.0, 1.0, 1.0));

      assert(0.5 * ph.M_PI == ph.forceFromDrag(1.0, 1.0, 1.0, 1.0));

      assert(1.0 * ph.M_PI == ph.forceFromDrag(2.0, 1.0, 1.0, 1.0));
      assert(1.0 * ph.M_PI == ph.forceFromDrag(1.0, 2.0, 1.0, 1.0));
      assert(2.0 * ph.M_PI == ph.forceFromDrag(1.0, 1.0, 2.0, 1.0));
      assert(2.0 * ph.M_PI == ph.forceFromDrag(1.0, 1.0, 2.0, 1.0));
      cout << "Pass Drag" << endl;
   }

   /******************************************************
   * TEST accelerationFromForce() to get the correct accelration when
   * calculated
   *******************************************************/
   void test_accelerationFromForce() const
   {
      //setup
      Physics ph;
      //exercise
      //verify
      assert(0.0 == ph.accelerationFromForce(0.0, 1.0));
      assert(1.0 == ph.accelerationFromForce(1.0, 1.0));
      assert(2.0 == ph.accelerationFromForce(2.0, 1.0));
      assert(0.5 == ph.accelerationFromForce(1.0, 2.0));
      cout << "Pass acceleration from force" << endl;
   }

   /******************************************************
   * TEST velocityFromAcceleration() to get the correct velocity when
   * calculated
   *******************************************************/

   void test_velocityFromAcceleration() const
   {
      //set up
      Physics ph;
      //exercise
      //verify
      assert(0.0 == ph.velocityFromAcceleration(0.0, 1.0));
      assert(0.0 == ph.velocityFromAcceleration(1.0, 0.0));

      assert(1.0 == ph.velocityFromAcceleration(1.0, 1.0));

      assert(2.0 == ph.velocityFromAcceleration(2.0, 1.0));
      assert(2.0 == ph.velocityFromAcceleration(1.0, 2.0));
      cout << "Pass velosity from acceleration" << endl;
   }

   /******************************************************
  * TEST linearInterpolation() to get the correct value
  * when going to be when getting drag, mach, density
  *******************************************************/
   void test_linearInterpolation() const
   {
      //setup
      Physics ph;
      //exercise
      //verify
      assert(0.00 == ph.linearInterpolation(0.0, 0.0, 0.0, 0.0, 0.00));
      assert(0.00 == ph.linearInterpolation({ 0.0, 0.0 }, { 0.0, 0.0 }, 0.00));

      assert(0.00 == ph.linearInterpolation(0.0, 0.0, 2.0, 0.0, 1.00));
      assert(1.00 == ph.linearInterpolation(0.0, 0.0, 2.0, 2.0, 1.00));
      assert(0.00 == ph.linearInterpolation({ 0.0, 0.0 }, { 2.0, 0.0 }, 1.00));
      assert(1.00 == ph.linearInterpolation({ 0.0, 0.0 }, { 2.0, 2.0 }, 1.00));

      assert(2.25 == ph.linearInterpolation(1.0, 2.0, 2.0, 3.0, 1.25));
      assert(2.75 == ph.linearInterpolation(1.0, 2.0, 2.0, 3.0, 1.75));
      assert(2.25 == ph.linearInterpolation({ 1.0, 2.0 }, { 2.0, 3.0 }, 1.25));
      assert(2.75 == ph.linearInterpolation({ 1.0, 2.0 }, { 2.0, 3.0 }, 1.75));

      assert(2.50 == ph.linearInterpolation(2.0, 2.0, 1.0, 3.0, 1.50));
      assert(2.25 == ph.linearInterpolation(2.0, 2.0, 1.0, 3.0, 1.75));
      assert(2.50 == ph.linearInterpolation({ 2.0, 2.0 }, { 1.0, 3.0 }, 1.50));
      assert(2.25 == ph.linearInterpolation({ 2.0, 2.0 }, { 1.0, 3.0 }, 1.75));

      cout << "Pass test_linearInterpolation" << endl;

   }

   /******************************************************
    * TEST  gravityFromAltitude() to get correct gravity
    * from linearInterpolation()
    *******************************************************/
   void test_gravityFromAltitude() const
   {
      //setup
      Physics ph;
      //exercise
      //verify
      assert(9.807 == ph.gravityFromAltitude(0.0));
      assert(9.8049 <= ph.gravityFromAltitude(666.6) &&
         9.8051 >= ph.gravityFromAltitude(666.6));
      assert(9.7919 <= ph.gravityFromAltitude(4666.6) &&
         9.7921 >= ph.gravityFromAltitude(4666.6));
      assert(9.7809 <= ph.gravityFromAltitude(8333.3) &&
         9.7811 >= ph.gravityFromAltitude(8333.3));
      assert(9.73 <= ph.gravityFromAltitude(79666.6) &&
         9.856 >= ph.gravityFromAltitude(79666.6));
   }
   /******************************************************
    * TEST  gravityFromAltitude() to get correct density
    * from linearInterpolation()
    *******************************************************/
   void test_densityFromAltitude() const
   {
      //set up
      Physics ph;
      //exercise
      //verify
      assert(1.2250000 == ph.densityFromAltitude(0.0));
      assert(1.059 <= ph.densityFromAltitude(1500.0) &&
         1.060 >= ph.densityFromAltitude(1500.0));
      assert(0.8110 <= ph.densityFromAltitude(4100.0) &&
         0.8112 >= ph.densityFromAltitude(4100.0));
      assert(0.0000184 <= ph.densityFromAltitude(80000.0) &&
         0.0000186 >= ph.densityFromAltitude(80000.0));
      cout << "Pass test_densityFromAltitude" << endl;
   }

   /******************************************************
    * TEST  speedOfSoundFromAltitude() to get coorect speed of
    * sound from linearInterpolation()
    *******************************************************/
   void test_speedOfSoundFromAltitude() const
   {
      //setup
      Physics ph;
      // verify
      assert(340 == ph.speedOfSoundFromAltitude(0.0));
      assert(333 <= ph.speedOfSoundFromAltitude(1500.0)
         && 335 >= ph.speedOfSoundFromAltitude(1500.0));
      assert(322 <= ph.speedOfSoundFromAltitude(4300.0)
         && 324 >= ph.speedOfSoundFromAltitude(4300.0));
      assert(324 <= ph.speedOfSoundFromAltitude(40001));
      cout << "Pass test_speedOfSoundFromAltitude" << endl;
   }


};
