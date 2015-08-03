#include "Ball.h"
#include "Bitmap.h"

//constructor
Ball::Ball()
{
	ballImage = new Bitmap("magic_ball.bmp", true);
}

//decontructor
Ball::~Ball()
{

}

void Ball::draw()
{
	ballImage->drawAt(680, 100);
}

void Ball::reset()
{
	
}

void Ball::update()
{

}