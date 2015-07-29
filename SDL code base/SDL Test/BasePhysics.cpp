#include "BasePhysics.h"

//force = mass x acceleration
//constructor
BasePhysics::BasePhysics()
{
	image = new Bitmap("rocket2.bmp", false);
	Xpos = 500;
	Ypos = 700;
	Xvel = 0;
	Yvel = 0;
	accel = -2;
	mass = 50;
}

//deconstructor
BasePhysics::~BasePhysics(){

}

void BasePhysics::reset()
{

}

void BasePhysics::applyForce()
{

}

void BasePhysics::update(Uint32 deltaTime)
{
	float delta = ((float)deltaTime)/1000.f;


	Yvel += accel * delta;
	Ypos += Yvel * delta;
	Xpos += Xvel * delta;
}

void BasePhysics::draw(){

	image->drawAt(Xpos, Ypos);
}