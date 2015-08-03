#include "SeeSaw.h"

//constructor
SeeSaw::SeeSaw()
{

}

//deconstructor
SeeSaw::~SeeSaw()
{

}

void SeeSaw::draw()
{
	//Drawing the top of See-saw
	glBegin(GL_POLYGON);
		glVertex2f(350, 80);
		glVertex2f(750, 80);
		glVertex2f(750, 100);
		glVertex2f(350, 100);
	glEnd();
	//glFlush();

}

void SeeSaw::update()
{

}

void SeeSaw::reset()
{

}