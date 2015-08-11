#include "Ball.h"
#include "AngularWall.h"
#include "Bitmap.h"
#include "Utils.h"

#define R (0.7) //How much energy is conserved in bounce
//constructor

Ball::Ball()
{
	ballImage = new Bitmap("magic_ball.bmp", true);
	isUnderPhysicsControl = false;

	ballRadius = pixelsToMeters((ballImage->getHeight()) / 2);

	Xpos = pixelsToMeters(725);
	Ypos = pixelsToMeters(100) + ballRadius;
}

//deconstructor
Ball::~Ball()
{

}

void Ball::draw()
{

	glColor3f(1.f, 1.f, 1.f);
	ballImage->drawAt(metersToPixels(Xpos), metersToPixels(Ypos), true);

	if (ballStatsLabel)
		ballStatsLabel->draw(1200, 550);
	if (xPosLabel)
		xPosLabel->draw(1200, 520);
	if (yPosLabel)
		yPosLabel->draw(1200, 500);
	if (accelYLabel)
		accelYLabel->draw(1200, 480);
	if (accelXLabel)
		accelXLabel->draw(1200, 460);	
	if (yVelLabel)
		yVelLabel->draw(1200, 440);
	if (xVelLabel)
		xVelLabel->draw(1200, 420);
}

void Ball::reset()
{
	
}

void Ball::update(Uint32 deltaTime, AngularWall * wallAngle)
{
	BasePhysics::update(deltaTime);
	updateLabels(deltaTime);

	//Detect the collision with the ground
	if ((Ypos - ballRadius) < pixelsToMeters(10))
	{
		Ypos = pixelsToMeters(10.01) + ballRadius;
		Yvel = R *- Yvel;
		Xvel *= R;
	}

	//Collision detection with the right wall
	if ((Xpos + ballRadius) > pixelsToMeters(1490))
	{
		Xpos = pixelsToMeters(1489.99) - ballRadius;
		Yvel *= R;
		Xvel = R *- Xvel;
	}

	//Collision detection with the left wall
	if ((Xpos - ballRadius) < pixelsToMeters(10))
	{
		Xpos = pixelsToMeters(10.01) + ballRadius;
		Yvel *= R;
		Xvel = R *-Xvel;
	}

	//Collision detection against angular wall
	Vector2D pos(Xpos, Ypos);
	//For each side of the wall
	for (int i = 0; i < 4; i++)
	{
		//Get the start and end points of the line that represents this edge
		Vector2D start, end;
		wallAngle->getWallPoints(i, start, end);

		//Project the ball onto this line
		Vector2D point = GetClosestPointOnLineSegment(start, end, pos);

		float dist = (point - pos).length();

		// If the closest point on the line segment is within the bounds of our radius, then we have collided with it
		if (dist <= ballRadius)
		{
			Vector2D surfaceNormal = wallAngle->getSurfaceNormal(i);

			//Push the ball out so it isn't colliding anymore
			Vector2D newpos = point + (surfaceNormal * (ballRadius + pixelsToMeters(0.01)));
			Xpos = newpos.x;
			Ypos = newpos.y;

			//Since we have collided wih the wall, we need to bounce off it
			//To do so, we reflect the ball's velocity, around the wall's edge's surfacenormal
			//This code was adapted from: http://www.3dkingdoms.com/weekly/weekly.php?a=2
			Vector2D incoming(Xvel, Yvel);

			Vector2D result = surfaceNormal * incoming.dot(surfaceNormal);
			result *= -2.f;
			result += incoming;
			result *= R;

			Xvel = result.x;
			Yvel = result.y;
		}
	}
}