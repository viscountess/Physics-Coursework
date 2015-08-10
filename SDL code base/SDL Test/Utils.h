#ifndef UTILS_INCLUDED
#define UTILS_INCLUDED

#include "Vector.h"

Vector2D GetClosestPointOnLineSegment(const Vector2D& LinePointStart, const Vector2D& LinePointEnd,
	const Vector2D& testPoint);

const float degToRad(const float _deg);
const float pixelsToMeters(float _pixels);
const float metersToPixels(float _meters);

#endif // UTILS_INCLUDED