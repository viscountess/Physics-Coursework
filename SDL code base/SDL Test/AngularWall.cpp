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

//Returns a vector, representing the surface normal for a given edge
Vector2D AngularWall::getSurfaceNormal(int index)
{
	//Rotate by 90 degrees for edges 0 and 2 
	float angleOffset = ((index == 0) || (index == 2)) ? 90.f : 0.f;
	//Get angle in radians after converting 0 to 360 range
	float angle = degToRad(fmodf(wallAngle + angleOffset, 360.f));
	//Use trig to get normal. When sampling the narrow ends of the wall, the normal is the wall's main direction of slope
	//Thats why we rotate it by 90 degrees for the wider ends
	Vector2D wallNormal;
	wallNormal.x = cos(angle);
	wallNormal.y = sin(angle);

	//The normals are pointing in the opposite direction on the other sides of the wall
	if (index == 2 || index == 3)
		wallNormal *= -1.f;

	return wallNormal;
}

//For a given edge, this function will return the start and end points of the line that represents it
void AngularWall::getWallPoints(int index, Vector2D& start, Vector2D& end)
{
	//Get the normal for this edge
	Vector2D normal = getSurfaceNormal(index);
	//The lateral is the direction that the line is currently moving in
	//& is the same as the normal of the next edge (moving clockwise)
	int lateralIdx = index + 1;
	if (lateralIdx >= 4) //wrap around back to 0
		lateralIdx = 0;

	Vector2D lateral = getSurfaceNormal(lateralIdx);

	//If edge 0 or 2 (long egdes)  
	if (index == 0 || index == 2)
	{
		//Start is equal to the position (midpoint) plus half of height of wall in the direction of the normal minus half of the width in the direction of the lateral
		start = Vector2D(xpos, ypos) + (normal * (wallHeight / 2)) - (lateral * (wallWidth / 2));
		//End is same as start, except we add the width instead of subtract
		end = Vector2D(xpos, ypos) + (normal * (wallHeight / 2)) + (lateral * (wallWidth / 2));
	}
	else
	{
		//Swap height and width for other edges
		start = Vector2D(xpos, ypos) + (normal * (wallWidth / 2)) - (lateral * (wallHeight / 2));
		end = Vector2D(xpos, ypos) + (normal * (wallWidth / 2)) + (lateral * (wallHeight / 2));
	}
}