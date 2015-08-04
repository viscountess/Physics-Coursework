#include "Ball.h"
#include "Bitmap.h"

//constructor
Ball::Ball()
{
	ballImage = new Bitmap("magic_ball.bmp", true);
	isUnderPhysicsControl = false;

	Xpos = 700;
	Ypos = 100;

	//Initiatlising NULL pointers so that we dont accidently delete them
	accelLabel = nullptr;
	xPosLabel = nullptr;
	yPosLabel = nullptr;
	yVelLabel = nullptr;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
}

//decontructor
Ball::~Ball()
{

}

void Ball::updateLabels(Uint32 deltaTime)
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
	if (accelLabel != 0)
		delete accelLabel;
	if (xPosLabel != 0)
		delete xPosLabel;
	if (yPosLabel != 0)
		delete yPosLabel;
	if (yVelLabel != 0)
		delete yVelLabel;

	//initialise new label objects
	accelLabel = new Label();
	xPosLabel = new Label();
	yPosLabel = new Label();
	yVelLabel = new Label();

	//create textures from strings
	char buffer[32];
	_snprintf(buffer, 32, "Acceleration: %.3f", accel);
	accelLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "X Position: %.3f", Xpos);
	xPosLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Y Position: %.3f", Ypos);
	yPosLabel->textToTexture(buffer, textFont, labelColor);

	_snprintf(buffer, 32, "Y Velocity: %.3f", Yvel);
	yVelLabel->textToTexture(buffer, textFont, labelColor);


}

void Ball::draw()
{
	ballImage->drawAt(Xpos, Ypos);

	if (accelLabel)
		accelLabel->draw(20, 160);
	if (xPosLabel)
		xPosLabel->draw(20, 180);
	if (yPosLabel)
		yPosLabel->draw(20, 200);
	if (yVelLabel)
		yVelLabel->draw(20, 220);
}

void Ball::reset()
{
	
}

void Ball::update(Uint32 deltaTime)
{
	BasePhysics::update(deltaTime);
	updateLabels(deltaTime);
}