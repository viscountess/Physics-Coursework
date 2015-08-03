#ifndef JUMPER_INCLUDE
#define JUMPER_INCLUDE

#include "BasePhysics.h"
#include "Bitmap.h"

class Jumper : public BasePhysics
{
public:
	//constructor
	Jumper();

	//deconstructor
	~Jumper();

	void draw();
	void reset();
	void update(Uint32 deltaTime);

private:
	Bitmap * jumperImage;  //create pointer for jumper image


};

#endif //JUMPER_INCLUDE