#ifndef SEESAW_INCLUDE
#define SEESAW_INCLUDE

#include "BasePhysics.h"

class SeeSaw
{
public:
	//constructor
	SeeSaw();

	//deconstructor
	~SeeSaw();

	void draw();
	void update();
	void reset();
private:
	float xPos, Ypos;

};

#endif //SEESAW_INCLUDE