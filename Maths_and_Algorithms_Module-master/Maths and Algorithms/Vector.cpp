#include "Vector.h"
#include <math.h>

//Constructor
Vector::Vector(float ax, float by)
{
	x = ax;
	y = by;
}

float Vector::Magnitude()
{
	return (sqrt((x * x) + (y * y)));
}

//Converting vector to have a magnitude of 1 e.g 3i + 5j -> 1/3i, 1/5j; 
void Vector::Normalise();
{
	//Get magnitude
	mag = Magnitude();
	//Divide x and y by magnitude
	normalisedX = x / mag;
	normalisedY = y / mag;
	//Update X and Y properties
	x = nomralisedX;
	y = normalisedY;

}