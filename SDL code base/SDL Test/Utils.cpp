#include "Utils.h"


Vector2D GetClosestPointOnLineSegment(const Vector2D& LinePointStart, const Vector2D& LinePointEnd,
	const Vector2D& testPoint)
{
	Vector2D LineDiffVect = LinePointEnd - LinePointStart;
	const float lineSegSqrLength = LineDiffVect.lengthSq();

	const Vector2D LineToPointVect = testPoint - LinePointStart;
	const float dotProduct = LineDiffVect.dot(LineToPointVect);

	const float percAlongLine = dotProduct / lineSegSqrLength;

	if (percAlongLine < 0.0f)
	{
		return LinePointStart;
	}
	else if (percAlongLine > 1.0f)
	{
		return LinePointEnd;
	}


	return (LinePointStart + (LineDiffVect * percAlongLine));// (percAlongLine * (LinePointEnd - LinePointStart));
}

const float degToRad(const float _deg)
{
	return _deg * 0.0174532925f;
}

const float metersToPixels(const float _meters)
{
	return _meters * 100;
}

const float pixelsToMeters(const float _pixels)
{
	return _pixels / 100.f;
}