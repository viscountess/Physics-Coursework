#include "AngularWall.h"
#include "Utils.h"
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

//constructor
AngularWall::AngularWall()
{
	xpos = pixelsToMeters(850);
	ypos = pixelsToMeters(250);
	wallAngle = -60;
	wallWidth = pixelsToMeters(700); 
	wallHeight = pixelsToMeters(10);
}

//deconstructor
AngularWall::~AngularWall()
{

}

void AngularWall::draw()
{
	glPushMatrix();
	glTranslatef(metersToPixels(xpos), metersToPixels(ypos), 0);
	glRotatef(wallAngle, 0, 0, 1);
	//Drawing angular wall
	glBegin(GL_POLYGON);
		glVertex2f(metersToPixels(-wallWidth/2), metersToPixels(wallHeight/2));
		glVertex2f(metersToPixels(wallWidth/2), metersToPixels(wallHeight/2));
		glVertex2f(metersToPixels(wallWidth/2), metersToPixels(-wallHeight/2));
		glVertex2f(metersToPixels(-wallWidth/2), metersToPixels(-wallHeight/2));
	glEnd();
	glPopMatrix();


	//wallAngle -= 0.7f;
}

Vector2D AngularWall::getSurfaceNormal(int _index)
{
	float angleOffset = ((_index == 0) || (_index == 2)) ? 90.f : 0.f;
	float angle = degToRad(fmodf(wallAngle + angleOffset, 360.f));

	Vector2D wallNormal;
	wallNormal.x = cos(angle);
	wallNormal.y = sin(angle);

	if (_index == 2 || _index == 3)
		wallNormal *= -1.f;

	return wallNormal;
}

void AngularWall::getWallPoints(int _index, Vector2D& _start, Vector2D& _end)
{
	Vector2D normal = getSurfaceNormal(_index);
	int lateralIdx = _index + 1;
	if (lateralIdx >= 4)
		lateralIdx = 0;

	Vector2D lateral = getSurfaceNormal(lateralIdx);

	if (_index == 0 || _index == 2)
	{
		_start = Vector2D(xpos, ypos) + (normal * (wallHeight / 2)) - (lateral * (wallWidth / 2));
		_end = Vector2D(xpos, ypos) + (normal * (wallHeight / 2)) + (lateral * (wallWidth / 2));
	}
	else
	{
		_start = Vector2D(xpos, ypos) + (normal * (wallWidth / 2)) - (lateral * (wallHeight / 2));
		_end = Vector2D(xpos, ypos) + (normal * (wallWidth / 2)) + (lateral * (wallHeight / 2));
	}
}