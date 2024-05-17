#include <iostream>

//#include "Algorithms.h"
//#include "DataStructures.h"
#include "Maths.h"
#include "Matrix.h"
#include "Vector.h"

#include <math.h>
#include <algorithm>

int main()
{
    std::cout << "Hello World!\n";
    //Testing degree and radian conversions, should output 3.14..., 360ish and 5
    std::cout << MathUtils::toRad(180.0f);
    std::cout << "\n";
    std::cout << MathUtils::toDeg(6.28f);
    std::cout << "\n";
    std::cout << MathUtils::Pythagoras(3, 4);
    std::cout << "\n";
    //vector
    Vector testVector(5,5);
    testVector.Normalise();
    std::cout << testVector.x << "\n";
    std::cout << testVector.y;
    //Stacks
    //Stack<int> newStack;
}




