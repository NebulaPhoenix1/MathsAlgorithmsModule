#include "Maths.h"

static float toRad(float Deg)
{
	float result = (MathUtils::pi * Deg) / 180.0f;
	return result;
}

static float toDeg(float Rad)
{
	float result = (180.0f * Rad) / MathUtils::pi;
	return result;
}

static float Pythagoras(float A, float B) //a^2 + b^2 = c^2
{
	float result = (A * A) + (B * B);
	return result;
}