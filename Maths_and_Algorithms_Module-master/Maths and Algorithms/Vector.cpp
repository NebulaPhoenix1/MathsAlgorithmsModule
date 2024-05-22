#include "Vector.h"
#include <math.h>
#include <iostream>

//Constructor
Vector::Vector(float ax, float by, float cz) : x(ax), y(by), z(cz) {}


float Vector::Magnitude()
{
	return (sqrt((x * x) + (y * y) + (z * z)));
}

//Converting vector to have a magnitude of 1 e.g 3i + 5j + 2k -> 1/3i, 1/5j, 1/2j; 
void Vector::Normalise()
{
	//Get magnitude
	float mag = Magnitude();
	//Divide x, y and z by magnitude
	float normalisedX = x / mag;
	float normalisedY = y / mag;
	float normalisedZ = z / mag;
	//Update X and Y properties
	x = normalisedX;
	y = normalisedY;
	z = normalisedZ;
}

//Multiply x, y and z by the scaler
void Vector::Scale(float scaler)
{
	x *= scaler;
	y *= scaler;
	z *= scaler;
}

float Vector::Dot(Vector& B)
{
	//Multiply same components by same component
	//Then add them together
	float dotX = x * B.x;
	float dotY = y * B.y;
	float dotZ = z * B.z;
	return (dotX + dotY + dotZ);
}

//Returns vector which is perpendicular to the two we're calculating cross product for
Vector Vector::Cross(Vector& B)
{
	//1 , 2, 3
	//4 , 5, 6
	//a x b == (aybz - azby)i, (azbx - axbz)j, (axby - aybx)k
	//Calculate I first 
	float i = (y * B.z) - (z*B.y); //12 - 15 = - 3
	//Then calculate J
	float j = (z*B.x) - (x*B.z); //12 - 6 = 6
	//Now calculate K
	float k = (x*B.y) - (y * B.x); //5 - 8 = -3
	//Now throw that in a vector and return
	return Vector(i, j, k);
}
