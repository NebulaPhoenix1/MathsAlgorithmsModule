#pragma once
namespace MathUtils
{
	static float toRad(float Deg);
	static float toDeg(float Rad);

	static float Pythagoras(float A, float B);

	static float FindSinTheta(float A, float B);
	static float FindCosTheta(float A, float B);
	static float FindTanTheta(float A, float B);

	static float FindHyp(float Angle, float B);
	static float FindOpp(float Angle, float B);
	static float FindAdj(float Angle, float B);

	static float pi = 3.14159;
}

