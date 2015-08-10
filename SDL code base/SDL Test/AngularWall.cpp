#include "AngularWall.h"
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

//constructor
AngularWall::AngularWall()
{

}

//deconstructor
AngularWall::~AngularWall()
{

}

void AngularWall::draw()
{
	//Drawing angular wall
	glBegin(GL_POLYGON);
		glVertex2f(500, 800);
		glVertex2f(520, 800);
		glVertex2f(1500, 0);
		glVertex2f(1500, -10);
	glEnd();
}