#include "Jumper.h"
#include "SDL.h"

//constructor
Jumper::Jumper()
{
	jumperImage = new Bitmap("jumper_close.bmp", true);

	isUnderPhysicsControl = true;
	Xpos = 350.0;
	Ypos = 700.0;
}

//deconstructor
Jumper::~Jumper()
{

}

void Jumper::draw()
{
	if (accelYLabel)
		accelYLabel->draw(20, 20);
	if (paraLabel)
		paraLabel->draw(20, 40);
	if (airDragLabel)
		airDragLabel->draw(20, 60);
	if (xPosLabel)
		xPosLabel->draw(20, 80);
	if (yPosLabel)
		yPosLabel->draw(20, 100);
	if (yVelLabel)
		yVelLabel->draw(20, 120);

	jumperImage->drawAt(Xpos, Ypos);
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

	if (Ypos <= 100)
		isUnderPhysicsControl = false;
	
}