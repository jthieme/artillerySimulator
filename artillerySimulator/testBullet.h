/******************************************************
* Course:
*    CSE 230 - Encapsulation Design
* Professor:
*    Brother Helfrich
* Authors:
*    Josh Thieme and Lakeram Narine
* Assignment:
*    W09 - Unit Tests
* Description:
*    This will have the unit tests to verify that the
*    Velocity class will work as designed.
* How long did this take?
*    About 2hrs
*******************************************************/
#pragma once
#include <iostream>
#include <cassert>


#include <iostream>
#include "position.h"
#include "ground.h"
#include <cassert>

/******************************************************
* TEST Bullet
* This class is a Unit Test to ensure that some of the
* Functions are working as needed
*******************************************************/

class TestBullet
{
	void run()
	{
		test_Bullet_begin_postion();
		test_bullet_current_position();
		test_bullet_hit_target();
		testing_isHit();
		test_coast_when_not_fired();
		test_bullet_state_when_bullet_coasting_at_zero();
		test_bullet_state_when_bullet_coasting_at_random();
		testing_bullet_move();
		test_when_bullet_hitground();
		test_updateAge();
		test_bullet_setAge();
		test_reset_bullet_state();

	}

	/******************************
	* Test setPostion(), the begin
	* position of the bullet, should be where
	* the howitzer is at
	********************/
	void test_Bullet_begin_postion()
	{
		// setup
		Howitzer pos(200, 300);
		Bullet bullet;
		// exercise
		bullet.setPosition();
		// verify
		assert(bullet.point.x = 200.0);
		assert(bullet.point.y = 300.0);
	}  // teardown


	/******************************
	* Test getPostion(), testing that
	* the getPosition returns the correct
	* result
	********************/
	void test_bullet_current_position()
	{
		// setup
		Position pos(200, 300);
		Bullet bullet(pos);
		// exercise
		bullet.point.x = 4;
		bullet.point.y = 4;
		// verify
		assert(bullet.getPosition() == (204, 304));
	}  // teardown

	/******************************
	* Test hitTarget(), to see
	* that the function detects
	* a collision
	********************/
	void test_bullet_hit_target()
	{
		// setup
		Position pos(200, 300);
		Ground ground.getTarget = pos;
		// exercise
		Bullet bullet(pos);
		// verify
		assert(bullet.hitTarget() == true);
	}  // teardown

	/******************************
	* Test isHit(), should return
	* true if either hit target
	* or hit ground
	********************/
	void testing_isHit()
	{
		// setup
		Bullet bullet;
		bullet.hitTarget() = true;
		// exercise
		bullet.hitGround() = false;
		// verify
		assert(bullet.isHit() == true);
	}  // teardown

	/******************************
	* Test coast(), should not be
	* applying any movement
	* when the status is inactive
	********************/
	void test_coast_when_not_fired()
	{
		// setup
		Position pos;
		Bullet bullet(pos);
		bullet.velosity.dx = 0.0;
		bullet.velosity.dy = 0.0;
		bullet.point.x = 0.0;
		bullet.point.y = 0.0;
		bullet.status = "Inactive";
		// exercise
		bullet.coast();
		// verify
		assert(bullet.velosity.getdx() == 0.0);
		assert(bullet.velosity.getdy() == 0.0);
		assert(bullet.point.getMetersX() == 0.0);
		assert(bullet.point.getMetersY() == 0.0);
	}  // teardown

	/******************************
	* Test coast(), when everything
	* is at zero
	 * newx = xInit + dx * time + (0.5 * updateDX()) * (time * time);
	 * newy = yInit + dy * time + (0.5 * updateDY()) * (time * time);
	********************/
	void test_bullet_state_when_bullet_coasting_at_zero()
	{
		// setup
		Position pos;
		Bullet bullet(pos);
		bullet.velosity.dx = 0.0;
		bullet.velosity.dy = 0.0;
		bullet.point.x = 0.0;
		bullet.point.Y = 0.0;
		bullet.status = "active";
		time = 1;
		// exercise
		bullet.coast();
		// verify
		assert(bullet.velosity.getdx() == 0.0);
		assert(bullet.velosity.getdy() == 0.0);
		assert(bullet.point.getMetersX() == 0.0);
		assert(bullet.point.getMetersY() == 0.0);
	}  // teardown

	/******************************
	* Test coast(), when everything
	* is at a certain value, testing if it will move
	* newx = xInit + dx * time + (0.5 * updateDX()) * (time * time);
	* newy = yInit + dy * time + (0.5 * updateDY()) * (time * time);
	* * -sin(radians) * calculateAcceleration();
	* gravity - cos(radians) * calculateAcceleration();
	********************/
	void test_bullet_state_when_bullet_coasting_at_random()
	{
		// setup
		Position pos;
		Bullet bullet(pos);
		bullet.acceleration = 1;
		bullet.velosity.dx = 3.4;
		bullet.velosity.dy = 3.4;
		bullet.point.x = 10.0;
		bullet.point.Y = 10.0;
		bullet.status = "active";
		Howitzer howitzer.radian = 1.0;
		gravity = 1;
		time = 1;
		// exercise
		bullet.coast();
		// verify
		assert(bullet.point.x < 16.0);
		assert(bullet.point.y < 16.0);
	}  // teardown

	/******************************
	* Test bulletMove(), this should
	* initialize all the movement
	* of the bullet
	********************/
	void testing_bullet_move()
	{
		// setup
		Position pos(200, 300);
		Bullet bullet(pos);
		bullet.status = "active";
		// exercise
		bullet.bulletMove();
		// verify
		assert(bullet.point.x > 200);
		assert(bullet.point.y > 300);
	}  // teardown

	/******************************
	* Test hitground(), this check
	* if there was bullet
	* and ground collision
	********************/
	void test_when_bullet_hitground()
	{
		// setup
		Position pos(200, 300);
		Bullet bullet(pos);
		// exercise
		Ground ground(pos);
		// verify
		assert(bullet.hitGround == true);
	}  // teardown

	/******************************
	* Test updateAge()
	********************/
	void test_updateAge()
	{
		// setup
		Bullet bullet;
		bullet.age = 1;
		// exercise
		bullet.updateAge(1);
		// verify
		assert(bullet.age == 2);
	}  // teardown

	/******************************
	* Test setAge()
	********************/
	void test_bullet_setAge()
	{
		// setup
		Bullet bullet;
		bullet.age = 3;
		// exercise
		bullet.setAge(1);
		// verify
		assert(bullet.age == 1);
	}  // teardown

	/******************************
	* Test rest(), should
	* reset all the state of the
	* bullet
	********************/
	void test_reset_bullet_state()
	{
		// setup
		Howitzer howitzer(200, 300);
		Bullet bullet;
		bullet.age = 3;
		bullet.point.setMetersX(300);
		bullet.point.setMetersY(200);
		bullet.velosity.setDX(3.0);
		bullet.velosity.setDY(3.0);
		bullet.velosity.getSpeed() = 7.9;
		bullet.status = "active";
		// exercise
		bullet.reset();
		// verify
		assert(bullet.age == 0);
		assert(bullet.getPosition() == howitzer.getPosition());
		assert(bullet.velosity.dx == 0.0);
		assert(bullet.velosity.dy == 0.0);
		assert(bullet.velosity.getSpeed() == 0.0);
		assert(bullet.status == "inActive");

	}  // teardown
};
