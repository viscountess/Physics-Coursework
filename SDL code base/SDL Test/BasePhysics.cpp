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

	//Initiatlising NULL pointers so that we dont accidently delete them
	accelLabel = nullptr;
	paraLabel = nullptr;
	airDragLabel = nullptr;
	xPosLabel = nullptr;
	yPosLabel = nullptr;
	yVelLabel = nullptr;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
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

void BasePhysics::updateLabels()
{
	SDL_Color labelColor = { 0, 255, 0 };

	//If the memory has been allocated already, then free it up
	//for the new label.
	if (accelLabel != 0)
		delete accelLabel;
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

	//initialise new label objects
	accelLabel = new Label();
	paraLabel = new Label();
	airDragLabel = new Label();
	xPosLabel = new Label();
	yPosLabel = new Label();
	yVelLabel = new Label();

	//create textures from strings
	char buffer[32];
	_snprintf(buffer, 32, "Acceleration: %.3f", accel);
	accelLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Parachute Open: %d", parachuteOpen);
	paraLabel->textToTexture(buffer, textFont, labelColor);


}

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

	//updateLabels();
}

void BasePhysics::draw(){

	image->drawAt(Xpos, Ypos);

	/*accelLabel->draw(20, 20);
	paraLabel->draw(20, 40);*/
}