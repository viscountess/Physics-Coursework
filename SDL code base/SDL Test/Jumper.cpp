#include "Jumper.h"
#include "Utils.h"
#include "SDL.h"

//constructor
Jumper::Jumper()
{
	jumperImage = new Bitmap("jumper_close.bmp", true);

	isUnderPhysicsControl = true;
	Xpos = pixelsToMeters(350.0);
	Ypos = pixelsToMeters(700.0);
}

//deconstructor
Jumper::~Jumper()
{

}

void Jumper::draw()
{
	if (playerStatsLabel)
		playerStatsLabel->draw(1200, 730);
	if (xPosLabel)
		xPosLabel->draw(1200, 700);
	if (yPosLabel)
		yPosLabel->draw(1200, 680);
	if (paraLabel)
		paraLabel->draw(1200, 660);
	if (airDragLabel)
		airDragLabel->draw(1200, 640);
	if (accelYLabel)
		accelYLabel->draw(1200, 620);
	if (yVelLabel)
		yVelLabel->draw(1200, 600);
	

	jumperImage->drawAt(metersToPixels(Xpos), metersToPixels(Ypos));
}

void Jumper::reset()
{

}

void Jumper::update(Uint32 deltaTime)
{
	BasePhysics::update(deltaTime);

	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE] && !parachuteOpen){
		parachuteOpen = true;
		delete jumperImage;
		jumperImage = new Bitmap("jumper_open.bmp", true);

	}

	if (Ypos <= pixelsToMeters(100))
		isUnderPhysicsControl = false;
	
}