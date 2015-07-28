#include<iostream>
#include<gl/glut.h>
#include "Bitmap.h"

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
	void applyForce();
	void update();
	void draw();

private:

	float Xpos, Ypos, Xvel, Yvel;
	Bitmap * image;		//create pointer for player image
};

#endif //BASEPHYSICS_INCLUDE