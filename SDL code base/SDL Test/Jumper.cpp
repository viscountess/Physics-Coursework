#include "Jumper.h"
#include "SDL.h"

//constructor
Jumper::Jumper()
{
	jumperImage = new Bitmap("jumper_close.bmp", true);

	Xpos = 500.0;
	Ypos = 700.0;
}

//deconstructor
Jumper::~Jumper()
{

}

void Jumper::draw()
{
	BasePhysics::draw();
	jumperImage->drawAt(Xpos, Ypos);
}

void Jumper::reset()
{

}

void Jumper::update(Uint32 deltaTime)
{
	BasePhysics::update(deltaTime);

	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE]){
		parachuteOpen = true;
		delete jumperImage;
		jumperImage = new Bitmap("jumper_open.bmp", true);

	}

	if (keys[SDL_SCANCODE_LEFT])
	{
		if (!parachuteOpen)
			Xpos -= 0.2;
		if (parachuteOpen)
			Xpos -= 0.05;
	}
}