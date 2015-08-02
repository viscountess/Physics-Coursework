#include<iostream>
#include<gl/glut.h>
#include "Bitmap.h"
#include <SDL.h>
#include "label.h"

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
	void updateLabels(Uint32 deltaTime);

	//Pointers for the text displayed onscreen (debug txt)
	Label * accelLabel;
	Label * paraLabel;
	Label * airDragLabel;
	Label * xPosLabel;
	Label * yPosLabel;
	Label * yVelLabel;

	TTF_Font* textFont;	// SDL type for True-Type font rendering

private:

	float Xpos, Ypos, Xvel, Yvel, accel;
	float mass;
	bool parachuteOpen;
	Bitmap * image;		//create pointer for player image
};

#endif //BASEPHYSICS_INCLUDE