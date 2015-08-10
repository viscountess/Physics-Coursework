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

	Vector2D getSurfaceNormal(int _index);
	void getWallPoints(int _index, Vector2D& _start, Vector2D& _end);

private:
	float xpos, ypos, wallAngle, wallWidth, wallHeight;

};

#endif //ANGULAR_WALL_INCLUDE