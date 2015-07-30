#include "BasePhysics.h"

//Gravity
#define G (10.0)

//Air drag - when chute is open
#define Ao (30.0)

//Air drag - when chute is closed
#define Ac (0.3)

//force = mass x acceleration
//constructor
BasePhysics::BasePhysics()
{
	image = new Bitmap("rocket2.bmp", false);
	Xpos = 500.0;
	Ypos = 700.0;
	Xvel = 0;
	Yvel = 0;
	accel = -G;
	mass = 80.0;
	parachuteOpen = false;
}

//deconstructor
BasePhysics::~BasePhysics(){

}

void BasePhysics::reset()
{

}

//void BasePhysics::applyForce(float hForce, float vForce)
//{
//
//}

void BasePhysics::update(Uint32 deltaTime)
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_SPACE]){
		parachuteOpen = true;

	}

	float delta = ((float)deltaTime)/1000.f;
	//accel = G - Ac

	float A = parachuteOpen ? Ao : Ac;

	//Getting the average force
	float avgForce = (mass * G) - (A * (Yvel * Yvel));

	accel = avgForce / mass;

	float nextYVel = Yvel + (accel * delta);
	Yvel = (Yvel + nextYVel) / 2.0; //finding average velocity

	//Finding next position
	Ypos = Ypos - (Yvel * delta);

	/*Yvel += accel * delta;
	Ypos += Yvel * delta;
	Xpos += Xvel * delta;*/
}

void BasePhysics::draw(){

	image->drawAt(Xpos, Ypos);
}