#include "Ball.h"
#include "Bitmap.h"

//constructor
Ball::Ball()
{
	ballImage = new Bitmap("magic_ball.bmp", true);
	isUnderPhysicsControl = false;

	Xpos = 700;
	Ypos = 100;
}

//decontructor
Ball::~Ball()
{

}

void Ball::draw()
{
	ballImage->drawAt(Xpos, Ypos);
}

void Ball::reset()
{
	
}

void Ball::update(Uint32 deltaTime)
{
	BasePhysics::update(deltaTime);
}