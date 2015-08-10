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
	
	Xvel = 0;
	Yvel = 0;
	accelY = -G;
	accelX = 0;
	mass = 50.0;
	parachuteOpen = false;

	//Initiatlising NULL pointers so that we dont accidently delete them
	accelYLabel = nullptr;
	accelXLabel = nullptr;
	paraLabel = nullptr;
	airDragLabel = nullptr;
	xPosLabel = nullptr;
	yPosLabel = nullptr;
	yVelLabel = nullptr;
	xVelLabel = nullptr;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
}

//deconstructor
BasePhysics::~BasePhysics()
{

}

void BasePhysics::reset()
{

}

//void BasePhysics::applyForce(float hForce, float vForce)
//{
//
//}

void BasePhysics::updateLabels(Uint32 deltaTime)
{
	SDL_Color labelColor = { 0, 255, 0 };
	static Uint32 lastUpdateTime = 0;

	//Update the labels every 30 hertz
	lastUpdateTime += deltaTime;

	if (lastUpdateTime < 33)
		return;

	lastUpdateTime = 0;

	//If the memory has been allocated already, then free it up
	//for the new label.
	if (accelYLabel != 0)
		delete accelYLabel;
	if (accelXLabel != 0)
		delete accelXLabel;
	if (paraLabel != 0)
		delete paraLabel;
	if (airDragLabel != 0)
		delete airDragLabel;
	if (xPosLabel != 0)
		delete xPosLabel;
	if (yPosLabel != 0)
		delete yPosLabel;
	if (yVelLabel != 0)
		delete yVelLabel;
	if (xVelLabel != 0)
		delete xVelLabel;

	//initialise new label objects
	accelYLabel = new Label();
	accelXLabel = new Label();
	paraLabel = new Label();
	airDragLabel = new Label();
	xPosLabel = new Label();
	yPosLabel = new Label();
	yVelLabel = new Label();
	xVelLabel = new Label();

	//create textures from strings
	char buffer[32];
	_snprintf(buffer, 32, "Y Acceleration: %.3f", accelY);
	accelYLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "X Acceleration: %.3f", accelX);
	accelXLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Parachute Open: %d", parachuteOpen);
	paraLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Air Drag: %.3f", parachuteOpen ? Ao : Ac);
	airDragLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "X Position: %.3f", Xpos);
	xPosLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Y Position: %.3f", Ypos);
	yPosLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Y Velocity: %.3f", Yvel);
	yVelLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "X Velocity: %.3f", Xvel);
	xVelLabel->textToTexture(buffer, textFont, labelColor);


}

void BasePhysics::update(Uint32 deltaTime)
{
	
	if (isUnderPhysicsControl)
	{
		float delta = ((float)deltaTime) / 1000.f;

		float B = (parachuteOpen ? Ao : Ac) / mass; // air drag - simplification from week 4's powerpoint slides

		// I found that if the ball was travelling upwards, the air drag was still applying a force upwards that caused the
		// ball to accelerate off the screen and never reappear. The air drag should either be a force in the opposite
		// direction of motion - or it should be 0 when travelling upwards. Since air resistance should always be present,
		// I am making it negative if the object is travelling upwards.
		if (Yvel > 0)
			B *= -1;

		accelY = -(G - (B * Yvel * Yvel)); // acceleration - after simplification from week 4's powerpoint slide

		// nextYVel is considered V(i+1) - the veloicty at the end of this step. YVel is our stored velocity - V(i)
		float nextYvel = Yvel + (accelY * delta);
		// work out average velocity
		float avgVel = (Yvel + nextYvel) / 2.f;
		Ypos = Ypos + (avgVel * delta);

		// store the Y Velocity
		Yvel = nextYvel;

		//Physics for X (left & right) direction
		B = (parachuteOpen ? Ao : Ac) / mass; // air drag - simplification from week 4's powerpoint slides

		if (Xvel > 0)
			B *= -1;

		accelX = -(0 - (B * Xvel * Xvel)); // acceleration - after simplification from week 4's powerpoint slide
		float nextXvel = Xvel + (accelX * delta);
		// work out average velocity
		avgVel = (Xvel + nextXvel) / 2.f;
		Xpos = Xpos + (Xvel * delta);

	}


	/*Yvel += accel * delta;
	Ypos += Yvel * delta;
	Xpos += Xvel * delta;*/

	updateLabels(deltaTime);
}

void BasePhysics::draw(){

	
}