#include "Maths.h"
#include <math.h>

float MathUtils::toRad(float Deg)
{
	float result = (MathUtils::pi * Deg) / 180.0f;
	return result;
}

float MathUtils::toDeg(float Rad)
{
	float result = (180.0f * Rad) / MathUtils::pi;
	return result;
}

float MathUtils::Pythagoras(float A, float B) //a^2 + b^2 = c^2
{
	float result = float(sqrt((A * A) + (B * B)));
	return result;
}

//Sin theta = opp/hyp
float MathUtils::FindSinTheta(float opp, float hyp)
{
	return (opp / hyp);
}

//Cos theta = adj/hyp
float MathUtils::FindCosTheta(float adj, float hyp)
{
	return (adj/hyp);
}

//Tan theta = opp/adj
float MathUtils::FindTanTheta(float opp, float adj)
{
	return(opp / adj);
}
