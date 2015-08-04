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

private:
	Bitmap * ballImage;		//create pointer for ball image
};

#endif //BALL_INCLUDE