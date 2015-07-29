#include<iostream>
#include<gl/glut.h>
#include "Bitmap.h"
#include <SDL.h>

#ifndef BASEPHYSICS_INCLUDE
#define BASEPHYSICS_INCLUDE

//Base class for all physics of guy & ball
class BasePhysics{
public:
	//constructor
	BasePhysics();

	//deconstructor
	~BasePhysics();

	void reset();
	void applyForce(float hForce, float vForce);
	void update(Uint32 deltaTime);
	void draw();

private:

	float Xpos, Ypos, Xvel, Yvel, accel;
	float mass;
	Bitmap * image;		//create pointer for player image
};

#endif //BASEPHYSICS_INCLUDE