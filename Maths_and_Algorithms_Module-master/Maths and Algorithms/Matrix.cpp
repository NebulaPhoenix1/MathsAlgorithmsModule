#include "Matrix.h"

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

void Matrix::SetRotateAroundX(float angle)
{
    
}

void Matrix::SetRotateAroundY(float angle)
{

}

void Matrix::SetRotateAroundZ(float angle)
{

}


