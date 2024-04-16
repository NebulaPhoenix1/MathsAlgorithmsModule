#pragma once
class Vector
{
public:
	float Magnitude();


	void Normalise();

	void Scale(float Scaler);

	float Dot(Vector& B);
	Vector Cross(Vector& B);

};

