/***********************************************************************
 * Header File:
 *    Howitzer : Represents the M777 Howitzer Tank in the artillery 
 *    simulation
 * Author:
 *    Josh Thieme
 * Summary:
 *    Everything about the Howitzer
 ************************************************************************/

#pragma once

#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Howitzer
{
private:
   double angle;
   double time;

public:
   void setPosition(Position p) 
   {
      p.setPixelsX(p.getPixelsX());
   }
   void draw(Position p, double angle, double time) {}
   void fire(double angle) {}
   double adjustAngle(double angle, const Interface* pUI)
   { 
      // move a large amount
      if (pUI->isRight())
         angle += 0.05;
      if (pUI->isLeft())
         angle -= 0.05;

      // move by a little
      if (pUI->isUp())
         angle += (angle >= 0 ? -0.003 : 0.003);
      if (pUI->isDown())
         angle += (angle >= 0 ? 0.003 : -0.003);

      return angle; 
   }
   void reset() {}
};