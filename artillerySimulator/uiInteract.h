/*********************************************
 * Header file:
 *    UI INTERFACE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This module will create an OpenGL window,
 *    enter the OpenGL main loop, and accept events.
 *    The main methods are:
 *    1. Constructors - Create the window
 *    2. run()        - Run the main loop
 *    3. callback     - Specified in Run, this user-provided
 *                      function will get called with every frame
 *    4. isDown()     - Is a given key pressed on this loop?
 **********************************************/

#pragma once

#include "position.h"
#include <algorithm> // used for min() and max() (specifically required by Visual Studio)
using std::min;
using std::max;

/********************************************
 * INTERFACE
 * All the data necessary to keep our graphics
 * state in memory
 ********************************************/
class Interface
{
public:
   Interface() {}

   // Constructor if you want to set up the window with anything but
   // the default parameters
   Interface(int argc, char** argv, const char* title, const Position& posUpperRight)
   {
      initialize(argc, argv, title, posUpperRight);
   }

   // This will set the game in motion
   void run(void (*callBack)(const Interface*, void*), void* p);

   // Is it time to redraw the screen
   bool isTimeToDraw();

   // Set the next draw time based on current time and time period
   void setNextDrawTime();

   // Retrieve the next tick time... the time of the next draw.
   unsigned int getNextTick() { return nextTick; };

   // How many frames per second are we configured for?
   void setFramesPerSecond(double value);

   // Key event indicating a key has been pressed or not.  The callbacks
   // should be the only onces to call this
   void keyEvent(int key, bool fDown);
   void keyEvent2(int key, bool fDown);
   void keyEvent();

   // Current frame rate
   double frameRate() const { return timePeriod; };

   // Get various key events
   int  isDown()      const { return isDownPress;  };
   int  isUp()        const { return isUpPress;    };
   int  isLeft()      const { return isLeftPress;  };
   int  isRight()     const { return isRightPress; };
   bool isSpace()     const { return isSpacePress; };


<<<<<<< HEAD
   // added new keys
   int  is4()         const { return is4Press; };
   int  is6()         const { return is6Press; };
   int  is8()         const { return is8Press; };
   int  is2()         const { return is2Press; };
   int is0()         const { return is0Press; };
=======
   // added new keys for 2nd player
   int isW()          const { return isWPress; };
   int isR()          const { return isRPress; };
   int isE()          const { return isEPress; };
   int isD()          const { return isDPress; };
   bool isX()         const { return isXPress; };
>>>>>>> b97230f230fb7af2913f4ee96f2a74711f50a417

   static void* p;                   // for client
   static void (*callBack)(const Interface*, void*);

private:
   void initialize(int argc, char** argv, const char* title, const Position& posUpperRight);

   static bool         initialized;  // only run the constructor once!
   static double       timePeriod;   // interval between frame draws
   static unsigned int nextTick;     // time (from clock()) of our next draw

   static int  isDownPress;          // is the down arrow currently pressed?
<<<<<<< HEAD
   static int  isUpPress;            //    "   up         "
   static int  isLeftPress;          //    "   left       "
   static int  isRightPress;         //    "   right      "
   static bool isSpacePress;         //    "   space      "
   // new key
   static int  is4Press;         //    "   W      "
   static int  is6Press;         //    "   R      "
   static int  is8Press;         //    "   W      "
   static int  is2Press;         //    "   R      "
   static int  is0Press;         //    "   R      "
=======
   static int  isUpPress;            //    "   up     "
   static int  isLeftPress;          //    "   left   "
   static int  isRightPress;         //    "   right  "
   static bool isSpacePress;         //    "   space  "
  
   // new keys for 2nd player
   static int  isWPress;             //    "   W      "
   static int  isRPress;             //    "   R      "
   static int  isEPress;             //    "   E      "
   static int  isDPress;             //    "   D      "
   static bool isXPress;             //    "   X      "
>>>>>>> b97230f230fb7af2913f4ee96f2a74711f50a417
};



/************************************************************************
 * DRAW CALLBACK
 * This is the main callback from OpenGL. It gets called constantly by
 * the graphics engine to refresh and draw the window.  Here we will
 * clear the background buffer, draw on it, and send it to the forefront
 * when the appropriate time period has passsed.
 *
 * Note: This and all other callbacks can't be member functions, they must
 * have global scope for OpenGL to see them.
 *************************************************************************/
void drawCallback();

/************************************************************************
 * KEY DOWN CALLBACK
 * When a key on the keyboard has been pressed, we need to pass that
 * on to the client.  Currnetly, we are only registering the arrow keys
 *************************************************************************/
void keyDownCallback(int key, int x, int y);

/************************************************************************
 * KEY UP CALLBACK
 * When the user has released the key, we need to reset the pressed flag
 *************************************************************************/
void keyUpCallback(int key, int x, int y);

/***************************************************************
 * KEYBOARD CALLBACK
 * Generic callback to a regular ascii keyboard event, such as
 * the space bar or the letter 'q'
 ***************************************************************/
void keyboardCallback(unsigned char key, int x, int y);

/************************************************************************
 * RUN
 * Set the game in action.  We will get control back in our drawCallback
 *************************************************************************/
void run();
