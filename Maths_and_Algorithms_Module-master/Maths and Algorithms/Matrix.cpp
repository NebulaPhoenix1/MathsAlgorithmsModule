#include "Matrix.h"
#include "Maths.h"
#include <math.h>

/* 
    A B C
det D E F = a x det e f - b x det d f + c x det d e  
    G H I           h i           g i           g h
*/

Matrix::Matrix(){}

float Matrix::Determinate()
{
    //det E F
    //    H I
    float first = Determinate2D(Data[1][1], Data[1][2], Data[2][1], Data[2][2]);
    //det D F
    //    G I
    float second = Determinate2D(Data[1][0], Data[1][2], Data[2][0], Data[2][2]);
    //det D E
    //    G H
    float third = Determinate2D(Data[1][0], Data[1][1], Data[2][0], Data[2][1]);
    float result = (Data[0][0] * first) - (Data[0][1] * second) + (Data[0][2] * third);
    return result;
}

float Matrix::Determinate2D(float a, float b, float c, float d)
{
    //Determinate = ad - bc
    return ((a * d) - (b * c));
}


//Return rotational matrices for rotation around different axis
void Matrix::SetRotateAroundX(float angle)
{
    Data[0][0] = 1;
    Data[0][0] = 0;
    Data[0][0] = 0;
    Data[1][0] = 0;
    Data[1][1] = cos(MathUtils::toRad(angle));
    Data[1][2] = -sin(MathUtils::toRad(angle));
    Data[2][0] = 0;
    Data[2][1] = sin(MathUtils::toRad(angle));
    Data[2][2] = cos(MathUtils::toRad(angle));
}

void Matrix::SetRotateAroundY(float angle)
{
    Data[0][0] = cos(MathUtils::toRad(angle));
    Data[0][0] = 0;
    Data[0][0] = sin(MathUtils::toRad(angle));
    Data[1][0] = 0;
    Data[1][1] = 1;
    Data[1][2] = 0;
    Data[2][0] = -sin(MathUtils::toRad(angle));
    Data[2][1] = 0;
    Data[2][2] = cos(MathUtils::toRad(angle));
}

void Matrix::SetRotateAroundZ(float angle)
{
    Data[0][0] = cos(MathUtils::toRad(angle));
    Data[0][0] = -sin(MathUtils::toRad(angle));
    Data[0][0] = sin(MathUtils::toRad(angle));
    Data[1][0] = cos(MathUtils::toRad(angle));
    Data[1][1] = 0;
    Data[1][2] = 0;
    Data[2][0] = 0;
    Data[2][1] = 0;
    Data[2][2] = 1;
}

//Assuming angles we're given are in degrees
//Just multiply vector by rotational matrix
Vector Matrix::RotateAroundX(Vector point, float Angle)
{
    Matrix rotMatrix;
    rotMatrix.SetRotateAroundX(Angle);
    return rotMatrix * point;
}

Vector Matrix::RotateAroundY(Vector point, float Angle)
{
    Matrix rotMatrix;
    rotMatrix.SetRotateAroundY(Angle);
    return rotMatrix * point;
}

Vector Matrix::RotateAroundZ(Vector point, float Angle)
{
    Matrix rotMatrix;
    rotMatrix.SetRotateAroundY(Angle);
    return rotMatrix * point;
}
