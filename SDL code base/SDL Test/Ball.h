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
	void update();

private:
	Bitmap * ballImage;		//create pointer for ball image
};

#endif //BALL_INCLUDE