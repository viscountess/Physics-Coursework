#include "BasePhysics.h"

//constructor
BasePhysics::BasePhysics()
{
	image = new Bitmap("rocket2.bmp", false);
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
void BasePhysics::update(){

}
void BasePhysics::draw(){

	image->drawAt(0, 0);
}