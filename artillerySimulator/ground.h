/***********************************************************************
 * Header File:
 *    Ground : Represents the ground in the artillery simulation
 * Author:
 *    Br. Helfrich, Josh Thieme, Lakeram Narine
 * Summary:
 *    Everything about the ground
 ************************************************************************/

#pragma once

#include "position.h"   // for Point
#include "uiDraw.h"

 /***********************************************************
  * GROUND
  * The ground class
  ***********************************************************/
class Ground
{
public:
    // the constructor generates the ground
    Ground(const Position& posUpperRight);

    // reset the game
    void reset(Position& posHowitzer, Position& posHowitzer2);

    // draw the ground on the screen
    void draw(ogstream& gout) const;

    // determine how high the Point is off the ground
    double getElevationMeters(const Position& pos) const
    {
        double pixelsX = pos.getPixelsX();
        double pixelsY = 0.0;
        if (pixelsX >= 0.0 && pixelsX < (int)posUpperRight.getPixelsX())
            pixelsY = ground[(int)pos.getPixelsX()];
        Position posImpact;
        posImpact.setPixelsY(pixelsY);
        return posImpact.getMetersY();
    }

    // where the the target located?
    const Position& getTarget() const
    {
        return posTarget;
    }

    bool hitGround(const Position& position, int bulletWidth) const;

    bool hitTarget(const Position& position) const;

private:
    double* ground;                // elevation of the ground, in pixels 
    Position posTarget;            // the location of the target, in pixels
    int iHowitzer;                 // the location of the howitzer for player 1
    int iHowitzer2;                // the location of the howtizer for player 2
    Position posUpperRight;        // size of the screen
};
