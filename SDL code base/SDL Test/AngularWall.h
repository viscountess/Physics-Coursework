#ifndef ANGULAR_WALL_INCLUDE
#define ANGULAR_WALL_INCLUDE
#include "Vector.h"

class AngularWall
{
public:
	//constructor
	AngularWall();

	//deconstructor
	~AngularWall();

	void draw();
	float getWallAngle() { return wallAngle; }
	float getWallHeight() { return wallHeight; }
	float getWallWidth() { return wallWidth; }
	float getWallXpos() { return xpos; }
	float getWallYpos() { return ypos; }

	Vector2D getSurfaceNormal(int index);
	void getWallPoints(int index, Vector2D& start, Vector2D& end);

private:
	float xpos, ypos, wallAngle, wallWidth, wallHeight;

};

#endif //ANGULAR_WALL_INCLUDE