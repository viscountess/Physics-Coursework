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

	//gluOrtho2D(0, 1500, 0, 1000);
	image->drawAt(50, 50);

	glColor3f(1, 1, 1);
	glBegin(GL_LINE);
	glVertex2d(-1, -1);
	glVertex2d(1, 1);
	glEnd();

}