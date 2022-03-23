#include "howitzer.h"

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