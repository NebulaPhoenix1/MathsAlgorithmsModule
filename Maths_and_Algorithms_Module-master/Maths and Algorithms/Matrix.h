#pragma once
#include "Vector.h"

class Matrix
{
public:

	Matrix(); //Constructor

	//this is a 3 x 3
	float Data[3][3] ;

	float Determinate();
	float Determinate2D(float a, float b, float c, float d);

	void SetRotateAroundX(float Angle);
	void SetRotateAroundY(float Angle);
	void SetRotateAroundZ(float Angle);


	Vector RotateAroundX(Vector Point, float Angle);
	Vector RotateAroundY(Vector Point, float Angle);
	Vector RotateAroundZ(Vector Point, float Angle);

	Matrix operator* (Matrix& RHS)
	{
    	Matrix& LHS = *this;
		Matrix Result;
		//fill this in to multiply Matrix LHS by Matrix RHS
		//First Row
		Result.Data[0][0] = ((LHS.Data[0][0] * RHS.Data[0][0]) + (LHS.Data[0][1] * RHS.Data[1][0]) + (LHS.Data[0][2] * RHS.Data[2][0]));
		Result.Data[0][1] = ((LHS.Data[0][0] * RHS.Data[0][1]) + (LHS.Data[0][1] * RHS.Data[1][1]) + (LHS.Data[0][2] * RHS.Data[2][1]));
		Result.Data[0][2] = ((LHS.Data[0][0] * RHS.Data[0][2]) + (LHS.Data[0][1] * RHS.Data[1][2]) + (LHS.Data[0][2] * RHS.Data[2][2]));
		//Second Row
		Result.Data[1][0] = ((LHS.Data[1][0] * RHS.Data[0][0]) + (LHS.Data[1][1] * RHS.Data[1][0]) + (LHS.Data[1][2] * RHS.Data[2][0]));
		Result.Data[1][1] = ((LHS.Data[1][0] * RHS.Data[0][1]) + (LHS.Data[1][1] * RHS.Data[1][1]) + (LHS.Data[1][2] * RHS.Data[2][1]));
		Result.Data[1][2] = ((LHS.Data[1][0] * RHS.Data[0][2]) + (LHS.Data[1][1] * RHS.Data[1][2]) + (LHS.Data[1][2] * RHS.Data[2][2]));
		//Third Row
		Result.Data[2][0] = ((LHS.Data[2][0] * RHS.Data[0][0]) + (LHS.Data[2][1] * RHS.Data[1][0]) + (LHS.Data[2][2] * RHS.Data[2][0]));
		Result.Data[2][1] = ((LHS.Data[2][0] * RHS.Data[0][1]) + (LHS.Data[2][1] * RHS.Data[1][1]) + (LHS.Data[2][2] * RHS.Data[2][1]));
		Result.Data[2][2] = ((LHS.Data[2][0] * RHS.Data[0][2]) + (LHS.Data[2][1] * RHS.Data[1][2]) + (LHS.Data[2][2] * RHS.Data[2][2]));

		return Result;
	}
	Vector operator* (Vector& RHS)
	{
		Matrix& LHS = *this;
		
		//fill this in to multiply Matrix LHS by Vector RHS
		float x = ((LHS.Data[0][0] * RHS.x) + (LHS.Data[0][1] * RHS.y) + (LHS.Data[0][2] * RHS.z));
		float y = ((LHS.Data[1][0] * RHS.x) + (LHS.Data[1][1] * RHS.y) + (LHS.Data[1][2] * RHS.z));
		float z = ((LHS.Data[2][0] * RHS.x) + (LHS.Data[2][1] * RHS.y) + (LHS.Data[2][2] * RHS.z));
		Vector Result(x, y, z);
		return Result;
	}

};