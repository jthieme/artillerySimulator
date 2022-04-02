/***************************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine
* Assignment:
*    W12 - Artillery Final
* Description:
*    This is the functions that will control the howitzer
*    it belongs to the howitzer class
*    code written.
* How long did this take?
*    About 10hrs 
****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "howitzer.h"   // for HOWITZER

/***************************************************************
* SET POSITION
* This will set the Intial Position of our Howtizer
****************************************************************/
void Howitzer::setPosition(Position& position)
{
	this->hposition.setPixelsX(position.getPixelsX());
	this->hposition.setPixelsY(position.getPixelsY());
}

/***************************************************************
* ROTATE
* FIRST HOWITZER CONTROL: Rotate the barrel for Howitzer One
***************************************************************/
void Howitzer::rotate(const Interface* pUI)
{
	if (pUI->isRight())
		angle += 0.05;
	if (pUI->isLeft())
		angle -= 0.05;
}

/***************************************************************
* RAISE
* FIRST HOWITZER CONTROL: Raise / move the barrel ofHowitzer One
* by small increments
***************************************************************/
void Howitzer::raise(const Interface* pUI)
{
	if (pUI->isUp())
		angle += (angle >= 0 ? -0.003 : 0.003);
	if (pUI->isDown())
		angle += (angle >= 0 ? 0.003 : -0.003);
}

/***************************************************************
* RAISE2
* SECOND HOWITZER CONTROL: Raise / move the barrel ofHowitzer Two
* by small increments
****************************************************************/
void Howitzer::raise2(const Interface* pUI)
{
	if (pUI->is8())
		angle += (angle >= 0 ? -0.003 : 0.003);
	if (pUI->is2())
		angle += (angle >= 0 ? 0.003 : -0.003);
}

/***************************************************************
* ROTATE2
* SECOND HOWITZER CONTROL: Rotate the barrel for Howitzer Two
***************************************************************/
void Howitzer::rotate2(const Interface* pUI)
{
	if (pUI->is4())
		angle += 0.05;
	if (pUI->is6())
		angle -= 0.05;
}