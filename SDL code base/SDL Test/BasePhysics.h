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
	virtual void update(Uint32 deltaTime);
	virtual void draw();
	void updateLabels(Uint32 deltaTime);
	bool getUnderPhysicsControl() { return isUnderPhysicsControl; }
	void setUnderPhysicsControl(bool physics) { isUnderPhysicsControl = physics; }
	float getMass() { return mass; }
	float getYVelocity() { return Yvel; }
	void setYVelocity(float YVel) { Yvel = YVel; Xvel = YVel; }
	float getXposition() { return Xpos; }

	//Pointers for the text displayed onscreen (debug txt)
	Label * accelYLabel;
	Label * accelXLabel;
	Label * paraLabel;
	Label * airDragLabel;
	Label * xPosLabel;
	Label * yPosLabel;
	Label * yVelLabel;
	Label * xVelLabel;
	Label * playerStatsLabel;
	Label * ballStatsLabel;

	TTF_Font* textFont;	// SDL type for True-Type font rendering

protected:

	float Xpos, Ypos, Xvel, Yvel, accelY, accelX;
	float mass;
	bool parachuteOpen;
	Bitmap * image;		//create pointer for player image
	bool isUnderPhysicsControl;
};

#endif //BASEPHYSICS_INCLUDE