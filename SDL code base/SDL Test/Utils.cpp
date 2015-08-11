#include "Utils.h"

//This function was adapted from code found on this page: http://www.cplusplus.com/forum/beginner/76692/
//It takes in two vectors representing the start and end points of a line, and a single point to test against
//The point is projected onto the line and clamped within the start and end point.
//We use this value when tsting for a circle colliding with this line segment.
Vector2D GetClosestPointOnLineSegment(const Vector2D& LinePointStart, const Vector2D& LinePointEnd,
	const Vector2D& testPoint)
{
	Vector2D LineDiffVect = LinePointEnd - LinePointStart;
	const float lineSegSqrLength = LineDiffVect.lengthSq();

	const Vector2D LineToPointVect = testPoint - LinePointStart;
	const float dotProduct = LineDiffVect.dot(LineToPointVect);

	const float percAlongLine = dotProduct / lineSegSqrLength;

	//This section clamps the value ebtween the start and end points
	//Without it, the point would be just projected onto the line
	if (percAlongLine < 0.0f)
	{
		return LinePointStart;
	}
	else if (percAlongLine > 1.0f)
	{
		return LinePointEnd;
	}

	return (LinePointStart + (LineDiffVect * percAlongLine));
}

const float degToRad(const float deg)
{
	return deg * 0.0174532925f;
}

const float metersToPixels(const float meters)
{
	return meters * 100;
}

const float pixelsToMeters(const float pixels)
{
	return pixels / 100.f;
}