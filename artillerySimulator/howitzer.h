/***********************************************************************
 * Header File:
 *    Howitzer : Represents the M777 Howitzer Tank in the artillery simulation
 * Author:
 *    Josh Thieme
 * Summary:
 *    Everything about the Howitzer
 ************************************************************************/

#pragma once

#include "position.h"
#include "uiDraw.h"

class Howitzer
{
private:
   double x;
   double angle;
   double time;

public:
   void setPosition(Position p) {}
   void draw(double x, double angle, double time) {}
   void fire(double angle) {}
   double adjustAngle(double angle) {};
   void reset() {};
};