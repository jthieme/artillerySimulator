/******************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine, James Helfrich
* Assignment:
*    W10 - Artillery FInal
* Description:
*    This is the functions that will control the howitzer
*    it belongs to the howitzer class
*    code written.
* How long did this take?
*    About 10hrs minutes
*******************************************************/


#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "howitzer.h"

/**********************************************
* This will set the Intial Position of our
* Howtizer
*****************************************/
void Howitzer::setPosition(Position& position)
{
	this->hposition.setPixelsX(position.getPixelsX());
	this->hposition.setPixelsY(position.getPixelsY());
}

/***********************************
* FIRST HOWITZER CONTROL: Rotate
* the Howitzer One
**********************************/
void Howitzer::rotate(const Interface* pUI)
{
	if (pUI->isRight())
		angle += 0.05;
	if (pUI->isLeft())
		angle -= 0.05;
}

/***********************************
* FIRST HOWITZER CONTROL: Raise/ move
* the Howitzer One by small increments
**********************************/
void Howitzer::raise(const Interface* pUI)
{
	if (pUI->isUp())
		angle += (angle >= 0 ? -0.003 : 0.003);
	if (pUI->isDown())
		angle += (angle >= 0 ? 0.003 : -0.003);
}

/***********************************
* SECOND HOWITZER CONTROL: Raise/ move
* the Howitzer two by small increments
**********************************/
void Howitzer::raise2(const Interface* pUI)
{
	if (pUI->is8())
		angle += (angle >= 0 ? -0.003 : 0.003);
	if (pUI->is2())
		angle += (angle >= 0 ? 0.003 : -0.003);
}

/***********************************
* SECOND HOWITZER CONTROL: Rotate
* the Howitzer Two
**********************************/
void Howitzer::rotate2(const Interface* pUI)
{
	if (pUI->is4())
		angle += 0.05;
	if (pUI->is6())
		angle -= 0.05;
}


