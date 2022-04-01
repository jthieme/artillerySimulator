


#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "howitzer.h"

void Howitzer::setPosition(Position& position)
{
	this->hposition.setPixelsX(position.getPixelsX());
	this->hposition.setPixelsY(position.getPixelsY());
}

/***********************************
* FIRST HOWITZER CONTROL
**********************************/
void Howitzer::rotate(const Interface* pUI)
{
	if (pUI->isRight())
		angle += 0.05;
	if (pUI->isLeft())
		angle -= 0.05;
}

void Howitzer::raise(const Interface* pUI)
{
	if (pUI->isUp())
		angle += (angle >= 0 ? -0.003 : 0.003);
	if (pUI->isDown())
		angle += (angle >= 0 ? 0.003 : -0.003);
}

/***********************************
* SECOND HOWITZER CONTROL
**********************************/
void Howitzer::raise2(const Interface* pUI)
{
	if (pUI->is8())
		angle += (angle >= 0 ? -0.003 : 0.003);
	if (pUI->is2())
		angle += (angle >= 0 ? 0.003 : -0.003);
}

void Howitzer::rotate2(const Interface* pUI)
{
	if (pUI->is4())
		angle += 0.05;
	if (pUI->is6())
		angle -= 0.05;
}


