#pragma once
#include "Vector.h"


class Matrix
{
public:
	//this is a 3 x 3

	float Data[3][3] ;

	float Determinate();

	void RotateAroundX(float Angle);
	void RotateAroundY(float Angle);
	void RotateAroundZ(float Angle);

	void Translate(Vector Delta);

	void RotateAroundX(Vector Point, float Angle);
	void RotateAroundY(Vector Point, float Angle);
	void RotateAroundZ(Vector Point, float Angle);

	Matrix operator* (Matrix& RHS)
	{
		Matrix& LHS = *this;

		//fill this in to multiply Matrix LHS by Matrix RHS
	}

};

