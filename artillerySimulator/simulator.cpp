/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "bullet.h"
#include "howitzerh.h"

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
    Demo(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        angle(0.0),
        isfired(false)

    {
        ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() * random(0.0, 1.0));
        ground.reset(ptHowitzer);
        howitzer.setPosition(ptHowitzer);
        Position hpos = howitzer.getPosition();
        bullet.setPosition(hpos);
    }

    Ground ground;                 // the ground
    Position  projectilePath;  // path of the projectile
    Position  ptHowitzer;          // location of the howitzer
    Position  ptUpperRight;        // size of the screen
    Howitzer howitzer;
    Bullet bullet;
    double angle;                  // angle of the howitzer 
    double time;               // amount of time since the last firing

    bool isfired;


    void draw(ogstream& gout, double dtime)
    {
        howitzer.draw(gout, dtime);
        ground.draw(gout);
        bullet.draw(gout);
    }

    void reset() {};

    void collision(ogstream& gout)
    {
        if (ground.hitGround(bullet.getPosition(), 0.8))
        {
            bullet.setIsFlying(false);
            gout << "You hit the Ground!!!" << "s\n";
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
    Demo* pDemo = (Demo*)p;
    ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));

    // move the howitzer
    pDemo->howitzer.rotate(pUI);
    pDemo->howitzer.raise(pUI);

    // Intialize the movement of the bullet
    if (pUI->isSpace())
    {
        pDemo->time = 0.0;
        if (!pDemo->bullet.getIsFlying()) {
            double angle = pDemo->howitzer.getAngle();
            Position pos = pDemo->howitzer.getPosition();
            pDemo->bullet.fire(angle, pos);
        }

    }
    // advance time by half a second.
    pDemo->time += 0.5;

    //Draw all the elements on the screen
    pDemo->draw(gout, pDemo->time);

    //Advance the bullet
    pDemo->bullet.advance();

    //Continually watch for Collision
    pDemo->collision(gout);

    // draw some text on the screen
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout << "Time since the bullet was fired: "
        << pDemo->time << "s\n";
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
        "Demo",   /* name on the window */
        ptUpperRight);

    // Initialize the demo
    Demo demo(ptUpperRight);

    // set everything into action
    ui.run(callBack, &demo);


    return 0;
}
m