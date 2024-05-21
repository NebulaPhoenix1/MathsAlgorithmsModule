#include "Vector.h"
#include <math.h>

//Constructor
Vector::Vector(float ax, float by) : x(ax), y(by) {}


float Vector::Magnitude()
{
	return (sqrt((x * x) + (y * y)));
}

//Converting vector to have a magnitude of 1 e.g 3i + 5j -> 1/3i, 1/5j; 
void Vector::Normalise()
{
	//Get magnitude
	float mag = Magnitude();
	//Divide x and y by magnitude
	float normalisedX = x / mag;
	float normalisedY = y / mag;
	//Update X and Y properties
	x = normalisedX;
	y = normalisedY;

}

//Multiply x and y by the scaler
void Vector::Scale(float scaler)
{
	x *= scaler;
	y *= scaler;
}

float Vector::Dot(Vector& B)
{
	//Multiply same components by same component
	//Then add them together
	float dotX = x * B.x;
	float dotY = y * B.y;
	return (dotX + dotY);
}

