#include "Ball.h"
#include "AngularWall.h"
#include "Bitmap.h"
#include "Utils.h"

#define R (0.7) //How much energy is conserved in bounce
//constructor

static AngularWall* s_wallAngle = 0;
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
	if (s_wallAngle)
	{

		//for (int i = 0; i < 4; i++)
		{

			/*Vector2D wallNormal = s_wallAngle->getSurfaceNormal(i);

			glColor3f(1.f, 0.f, 0.f);
			glLineWidth(10.f);

			glBegin(GL_LINES);
			glVertex2d(s_wallAngle->getWallXpos(), s_wallAngle->getWallYpos());
			glVertex2d(s_wallAngle->getWallXpos() + (wallNormal.x * 50), s_wallAngle->getWallYpos() + (wallNormal.y * 50));
			glEnd();*/

			//glPointSize(10);
			//for (int i = 0; i < 4; i++)
			/*{
				Vector2D wallStart, wallEnd;
				s_wallAngle->getWallPoints(3, wallStart, wallEnd);

				glColor3f(1.f, 0.f, 0.f);
				glBegin(GL_POINTS);
				glVertex2d(wallStart.x, wallStart.y);
				glEnd();

				glColor3f(0.f, 1.f, 0.f);
				glBegin(GL_POINTS);
				glVertex2f(wallEnd.x, wallEnd.y);
				glEnd();
			}*/
		}
	}

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
		printf("Hit right wall\n");
	}

	//Collision detection with the left wall
	if ((Xpos - ballRadius) < pixelsToMeters(10))
	{
		Xpos = pixelsToMeters(10.01) + ballRadius;
		Yvel *= R;
		Xvel = R *-Xvel;
		printf("Hit left wall\n");
	}

	//Collision detection against angular wall

	s_wallAngle = wallAngle;

	Vector2D pos(Xpos, Ypos);
	for (int i = 0; i < 4; i++)
	{
		Vector2D start, end;
		wallAngle->getWallPoints(i, start, end);

		Vector2D point = GetClosestPointOnLineSegment(start, end, pos);

		float dist = (point - pos).length();

		// If the closest point on the line segment is within the bounds of our radius, then we have collided with it
		if (dist <= ballRadius)
		{
			
			Vector2D surfaceNormal = wallAngle->getSurfaceNormal(i);

			Vector2D newpos = point + (surfaceNormal * (ballRadius + pixelsToMeters(0.01)));
			Xpos = newpos.x;
			Ypos = newpos.y;

			Vector2D incoming(Xvel, Yvel);

			Vector2D result = surfaceNormal * incoming.dot(surfaceNormal);
			result *= -2.f;
			result += incoming;
			result *= R;

			Xvel = result.x;
			Yvel = result.y;

			printf("Hit angular wall\n");
		}
	}
}