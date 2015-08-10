#include "Ball.h"
#include "Bitmap.h"

#define R (0.9) //How much energy is conserved in bounce
//constructor
Ball::Ball()
{
	ballImage = new Bitmap("magic_ball.bmp", true);
	isUnderPhysicsControl = false;

	////Initiatlising NULL pointers so that we dont accidently delete them
	//accelYLabel = nullptr;
	//accelXLabel = nullptr;
	//xPosLabel = nullptr;
	//yPosLabel = nullptr;
	//yVelLabel = nullptr;

	//textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	ballRadius = (ballImage->getHeight()) / 2;

	Xpos = 725;
	Ypos = 100 + ballRadius;
}

//decontructor
Ball::~Ball()
{

}

//void Ball::updateLabels(Uint32 deltaTime)
//{
//	SDL_Color labelColor = { 0, 255, 0 };
//	static Uint32 lastUpdateTime = 0;
//
//	//Update the labels every 30 hertz
//	lastUpdateTime += deltaTime;
//
//	if (lastUpdateTime < 33)
//		return;
//
//	lastUpdateTime = 0;
//
//	//If the memory has been allocated already, then free it up
//	//for the new label.
//	if (accelYLabel != 0)
//		delete accelYLabel;
//	if (accelXLabel != 0)
//		delete accelXLabel;
//	if (xPosLabel != 0)
//		delete xPosLabel;
//	if (yPosLabel != 0)
//		delete yPosLabel;
//	if (yVelLabel != 0)
//		delete yVelLabel;
//
//	//initialise new label objects
//	accelYLabel = new Label();
//	xPosLabel = new Label();
//	yPosLabel = new Label();
//	yVelLabel = new Label();
//
//	//create textures from strings
//	char buffer[32];
//	_snprintf(buffer, 32, "Y Acceleration: %.3f", accelY);
//	accelYLabel->textToTexture(buffer, textFont, labelColor);
//
//	_snprintf(buffer, 32, "X Acceleration: %.3f", accelX);
//	accelXLabel->textToTexture(buffer, textFont, labelColor);
//
//	_snprintf(buffer, 32, "X Position: %.3f", Xpos);
//	xPosLabel->textToTexture(buffer, textFont, labelColor);
//
//	_snprintf(buffer, 32, "Y Position: %.3f", Ypos);
//	yPosLabel->textToTexture(buffer, textFont, labelColor);
//
//	_snprintf(buffer, 32, "Y Velocity: %.3f", Yvel);
//	yVelLabel->textToTexture(buffer, textFont, labelColor);
//
//
//}


void Ball::draw()
{
	ballImage->drawAt(Xpos, Ypos, true);

	if (accelYLabel)
		accelYLabel->draw(20, 180);
	if (accelXLabel)
		accelXLabel->draw(20, 200);
	if (xPosLabel)
		xPosLabel->draw(20, 220);
	if (yPosLabel)
		yPosLabel->draw(20, 240);
	if (yVelLabel)
		yVelLabel->draw(20, 260);
	if (xVelLabel)
		xVelLabel->draw(20, 280);
}

void Ball::reset()
{
	
}

void Ball::update(Uint32 deltaTime)
{
	BasePhysics::update(deltaTime);
	updateLabels(deltaTime);

	//Detect the collision with the ground
	if ((Ypos - ballRadius) < 10)
	{
		Ypos = 10 + ballRadius;
		Yvel = R *- Yvel;
		Xvel *= R;
	}

	//Collision detection with the right wall
	if ((Xpos + ballRadius) > 1490)
	{
		Xpos = 1490 - ballRadius;
		Yvel *= R;
		Xvel = R *- Xvel;
	}

	//Collision detection with the left wall
	if ((Xpos - ballRadius) < 10)
	{
		Xpos = 10 + ballRadius;
		Yvel *= R;
		Xvel = R *-Xvel;
	}
}