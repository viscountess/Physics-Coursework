#ifndef BALL_INCLUDE
#define BALL_INCLUDE

#include "BasePhysics.h"
#include "AngularWall.h"
#include "Bitmap.h"
#include "Vector.h"

class Ball : public BasePhysics
{
public:
	//constructor
	Ball();

	//decontructor
	~Ball();

	void draw();
	void reset();
	void update(Uint32 deltaTime, AngularWall * wallAngle);
	//void updateLabels(Uint32 deltaTime);

private:
	Bitmap * ballImage;		//create pointer for ball image

	float ballRadius;
};

#endif //BALL_INCLUDE