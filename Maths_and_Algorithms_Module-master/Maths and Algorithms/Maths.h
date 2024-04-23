#pragma once
namespace MathUtils
{
	float toRad(float Deg);
	float toDeg(float Rad);

	float Pythagoras(float A, float B);

	float FindSinTheta(float A, float B);
	float FindCosTheta(float A, float B);
	float FindTanTheta(float A, float B);

	float FindHyp(float Angle, float B);
	float FindOpp(float Angle, float B);
	float FindAdj(float Angle, float B);

	static float pi = 3.1415f;
}

