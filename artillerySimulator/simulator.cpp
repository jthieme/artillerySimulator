/*************************************************************
 * 1. Name:
 *      Simulator
 * 2. Assignment Name:
 *      Lab 12: Code Complete
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      Ensuring that the collision detection was there, as well
 *      as getting the bullet to fire in the direction of the 
 *      howitzer
 * 5. How long did it take for you to complete the assignment?
 *      ~ 6 hours
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "bullet.h"
#include "howitzer.h"

using namespace std;

/*************************************************************************
 * Simulator
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
    Simulator(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        angle(0.0),
        isfired(false)

    {
        ptHowitzerOne[1].setPixelsX(Position(ptUpperRight).getPixelsX() / 1.2  );
        ptHowitzerOne[2].setPixelsX(Position(ptUpperRight).getPixelsX() / 2.5);
      
        ground.reset(ptHowitzerOne[1], ptHowitzerOne[2]);
      
        hPlayerOne.setPosition(ptHowitzerOne[1]);
        hPlayerTwo.setPosition(ptHowitzerOne[2]);

        Position hPosOne = hPlayerOne.getPosition();
        Position hPosOne2 = hPlayerTwo.getPosition();
        bullet.setPosition(hPosOne);
        bullet2.setPosition(hPosOne2);
    }

    Ground ground;                 // the ground
    Position  projectilePath;  // path of the projectile
    Position  ptHowitzerOne[2];          // location of the howitzer
                                         // location of the howitzer
    Position  ptUpperRight;        // size of the screen
    Howitzer hPlayerOne;
    Howitzer hPlayerTwo;
    Bullet bullet;
    Bullet bullet2;
    double angle;                  // angle of the howitzer 
    double time;               // amount of time since the last firing
    bool isfired;

    void draw(ogstream& gout, double dtime)
    {
        hPlayerOne.draw(gout, dtime);
        hPlayerTwo.draw(gout, dtime);
        ground.draw(gout);

        bullet2.draw(gout);
        bullet.draw(gout);
       
        
    }

    void reset() {};

    void collision(ogstream& gout)
    {
        // check if Bullet 1 hit target
        if (ground.hitTarget(bullet.getPosition()))
        {
            bullet.setIsFlying(false);
            bullet2.setIsFlying(false);
            gout << "Player One  hit the Target!!!" << "\n";
        }
        // check if bullet 2 hit target
        if (ground.hitTarget(bullet2.getPosition()))
        {
            bullet.setIsFlying(false);
            bullet2.setIsFlying(false);
            gout << "Player Two hit the Target!!!" << "\n";
        }

        if (ground.hitGround(bullet.getPosition(), 0.8))
        {
            bullet.setIsFlying(false);
            gout << "Player One hit the Ground!!!" << "\n";
        }

        // check if bullet two hit the ground
        if (ground.hitGround(bullet2.getPosition(), 0.8))
        {
            bullet2.setIsFlying(false);
            gout << "Player Two hit the Ground!!!" << "\n";
        }
    }
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Simulator* pSimulator = (Simulator*)p;
    ogstream gout(Position(10.0, pSimulator->ptUpperRight.getPixelsY() - 20.0));

    // move the howitzer
    pSimulator->hPlayerOne.rotate(pUI);
    pSimulator->hPlayerOne.raise(pUI);

    pSimulator->hPlayerTwo.rotate2(pUI);
    pSimulator->hPlayerTwo.raise2(pUI);

    // Intialize the movement of the bullet
    if (pUI->isSpace())
    {
        pSimulator->time = 0.0;
        if (!pSimulator->bullet.getIsFlying()) {
            double angle = pSimulator->hPlayerOne.getAngle();
            Position pos = pSimulator->hPlayerOne.getPosition();
            pSimulator->bullet.fire(angle, pos);
        }

    }
    // second Howitzer
    if (pUI->isX())
    {
        pSimulator->time = 0.0;
        if (!pSimulator->bullet2.getIsFlying()) {
            double angle = pSimulator->hPlayerTwo.getAngle();
            Position pos = pSimulator->hPlayerTwo.getPosition();
            pSimulator->bullet2.fire(angle, pos);
        }
    }

    // advance time by half a second.
    pSimulator->time += 0.5;

    //Draw all the elements on the screen
    pSimulator->draw(gout, pSimulator->time);

    //Advance the bullet
    pSimulator->bullet.advance();
    pSimulator->bullet2.advance();

    //Continually watch for Collision
    pSimulator->collision(gout);

    // draw some text on the screen
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Time since the bullet was fired: "
        << pSimulator->time << "s\n";
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32

int main(int argc, char** argv)
#endif // !_WIN32
{
    // Initialize OpenGL
    Position ptUpperRight;
    ptUpperRight.setPixelsX(700.0);
    ptUpperRight.setPixelsY(500.0);
    Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
    Interface ui(0, NULL,
        "Simulator",   /* name on the window */
        ptUpperRight);

    // Initialize the Simulator
    Simulator Simulator(ptUpperRight);

    // set everything into action
    ui.run(callBack, &Simulator);


    return 0;
}