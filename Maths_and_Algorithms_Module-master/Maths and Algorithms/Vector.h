#pragma once
class Vector
{
public:
	//Constructor
	Vector(float x, float y);

	//Sqaure root of x^2 and y^2
	float Magnitude();


	void Normalise();

	//Multiply whole vector by scaler
	void Scale(float Scaler);

	float Dot(Vector& B);
	Vector Cross(Vector& B);

	float x;
	float y;

};

