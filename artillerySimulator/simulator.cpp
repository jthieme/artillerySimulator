/*****************************************************************
 * 1. Name:
 *      Simulator
 * 2. Assignment Name:
 *      Lab 12: Artillery Final 
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      Ensuring that the collision detection was there, as well
 *      as getting the bullet to fire in the direction of the 
 *      howitzer, along with getting the trail of the bullet.
 * 5. How long did it take for you to complete the assignment?
 *      ~ 12 hours
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POINT
#include "bullet.h"     // for BULLET
#include "bullet.cpp"
#include "howitzer.h"   // for HOWITZER
#include "howitzer.cpp"

using namespace std;

/*************************************************************************
 * Simulator
 * Class that handles the gameplay
 *************************************************************************/
class Simulator
{

private:
   Ground ground;                 // the ground
   Position  projectilePath;      // path of the projectile
   Position  ptHowitzerOne[2];    // location of the howitzer
   Position  ptUpperRight;        // size of the screen
   Howitzer hPlayerOne;           // first howitzer instance
   Howitzer hPlayerTwo;           // second howitzer instance
   Bullet bullet;                 // first bullet for the first Howitzer
   Bullet bullet2;                // second bullet for the second Howitzer
   double angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing for first howitzer
   double time2;                  // amount of time since last firing for second howitzer
   bool bulletHitTarget = false;  // did the bullet for player 1 hit the target
   bool bullet2HitTarget = false; // did the bullet for player 2 hit the target 
   bool bulletHitGround = false;  // did the bullet for player 1 hit the ground
   bool bullet2HitGround = false; // did the bullet for player 2 hit the ground

public:
    /*************************************************
    * This is the Simulator constructor we intialize
    * the member variables here when an
    *************************************************/
    Simulator(Position ptUpperRight) :
        ptUpperRight(ptUpperRight),
        ground(ptUpperRight),
        time(0.0),
        time2(0.0),
        angle(0.0)

    {
        // set the Howitzers pixels
        ptHowitzerOne[0].setPixelsX(Position(ptUpperRight).getPixelsX() / 1.2);
        ptHowitzerOne[1].setPixelsX(Position(ptUpperRight).getPixelsX() / 2.5);
      
        // set the Howtizers on the ground
        ground.reset(ptHowitzerOne[0], ptHowitzerOne[1]);
      
        // set the Howitzers positions
        hPlayerOne.setPosition(ptHowitzerOne[0]);
        hPlayerTwo.setPosition(ptHowitzerOne[1]);

        // Grabbing howitzer position and give it to the bullet
        Position hPosOne = hPlayerOne.getPosition();
        Position hPosOne2 = hPlayerTwo.getPosition();

        bullet.setPosition(hPosOne);
        bullet2.setPosition(hPosOne2);
    }

    /************************************************
    * DRAW 
    * Display all the elements and objects on screen
    *************************************************/
    void draw(ogstream& gout, double dtime, double dtime2)
    {
        // draw each howitzer
        hPlayerOne.draw(gout, dtime);
        hPlayerTwo.draw(gout, dtime2);
        
        // draw the ground
        ground.draw(gout);

        // draw each bullet
        bullet2.draw(gout);
        bullet.draw(gout);   
    }

    /************************************************
    * CHECK COLLISION
    * This will check for collison of the bullets to
    * the ground and the Target
    ************************************************/
    void checkCollision(ogstream& gout)
    {
        // check if Bullet 1 hit target
        if (ground.hitTarget(bullet.getPosition()))
        {
            bullet.bulletCollide();
            bulletHitTarget = true;
        }

        // check if bullet 2 hit target
        if (ground.hitTarget(bullet2.getPosition()))
        {
            bullet2.bulletCollide();
            bullet2HitTarget = true;
        }
        // check if bullet 1 hit the ground
        if (ground.hitGround(bullet.getPosition(), 0.8))
        {
            bullet.bulletCollide();
            bulletHitGround = true;
        }

        // check if bullet 2 hit the ground
        if (ground.hitGround(bullet2.getPosition(), 0.8))
        {
            bullet2.bulletCollide();
            bullet2HitGround = true;
        }
    }
    
   /**************************************************
   * SIMULATOR INPUT
   * CHECK FOR USER KEY PRESSES: this will check for
   * user input and controls the Howitzer
   * accordingly
   ***************************************************/
    void simulatorInput(const Interface* pUI)
    {
        // move the howitzerOne
        hPlayerOne.rotate(pUI);
        hPlayerOne.raise(pUI);

        //move howitzerTwo
        hPlayerTwo.rotate2(pUI);
        hPlayerTwo.raise2(pUI);
                
        // Intialize the movement of the bullet from first Howitzer
        if (pUI->isSpace())
        {
            time = 0.0;
            if (!bullet.getIsFlying()) {
                double angle = hPlayerOne.getAngle();
                Position pos = hPlayerOne.getPosition();
                bullet.fire(angle, pos);
                bullet.setPath();
            }

        }
        // Intialize the movement of the bullet from second Howitzer
        if (pUI->isV())
        {
            time2 = 0.0;
            if (!bullet2.getIsFlying()) {
                double angle = hPlayerTwo.getAngle();
                Position pos = hPlayerTwo.getPosition();
                bullet2.fire(angle, pos);
                bullet2.setPath();
            }
        }
    }

    /**************************************************
    * DISPLAY GAME INFO 
    * Display the Game info on Screen
    **************************************************/
    void displayGameInfo(ogstream& gout)
    {
        // Display time since the Bullets fired
        gout.setf(ios::fixed | ios::showpoint);
        gout.precision(1);
        gout << "    Time since the bullet was fired: "
             << time << "s\n";

        // Display the Message for Collisions
        if (bulletHitTarget)
           gout << "               Player One hit the Target!!!" << "\n";
        else if (bulletHitGround)
           gout << "               Player One hit the Ground!!!" << "\n";
        
        if (bullet2HitTarget)
           gout << "               Player Two hit the Target!!!" << "\n";
        else if (bullet2HitGround)
           gout << "               Player Two hit the Ground!!!" << "\n";

    }

    /**************************************************
    * SET PLAYER ONE / TWO TIME
    * Increment time for gameplay
    **************************************************/
    double setPlayerOneTime() { return time += 0.5;  }
    double setPlayerTwoTime() { return time2 += 0.5; }

    /**************************************************
    * ENGAGE SIMULATOR
    * This allows for the simulator to function
    **************************************************/
    void engageSimulator(const Interface* pUI)
    {
       ogstream gout(Position(10.0, ptUpperRight.getPixelsY() - 20.0));
       ogstream gout2;

       // Getting the users INPUT
       simulatorInput(pUI);

       // advance time by half a second.
       setPlayerOneTime();
       setPlayerTwoTime();

       //Draw all the elements on the screen
       draw(gout, setPlayerOneTime(), setPlayerTwoTime());

       //Advance the bullet
       bullet.advance();
       bullet2.advance();

       //continually watch for Collision
       checkCollision(gout);

       // draw some text on the screen
       displayGameInfo(gout);
    }

};

/********************************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 ********************************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Simulator* pSimulator = (Simulator*)p;
   
    pSimulator->engageSimulator(pUI);
}

double Position::metersFromPixels = 40.0;

/*************************************************
 * Initialize the simulation and set it in motion
 ************************************************/
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