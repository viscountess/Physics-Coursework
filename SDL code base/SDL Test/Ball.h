#ifndef BALL_INCLUDE
#define BALL_INCLUDE

#include "BasePhysics.h"
#include "Bitmap.h"

class Ball : public BasePhysics
{
public:
	//constructor
	Ball();

	//decontructor
	~Ball();

	void draw();
	void reset();
	void update(Uint32 deltaTime);
	void updateLabels(Uint32 deltaTime);

private:
	Bitmap * ballImage;		//create pointer for ball image

	//Pointers for the text displayed onscreen (debug txt)
	Label * accelLabel;
	Label * xPosLabel;
	Label * yPosLabel;
	Label * yVelLabel;

	TTF_Font* textFont;	// SDL type for True-Type font rendering
};

#endif //BALL_INCLUDE