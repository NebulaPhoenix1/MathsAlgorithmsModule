#include <iostream>

#include "Algorithms.h"
//#include "DataStructures.h"
#include "Maths.h"
#include "Matrix.h"
#include "Vector.h"

#include <math.h>
#include <algorithm>

int main()
{
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
    std::cout << testVector.y << "\n";
    //Stacks
    //Stack<int> newStack;

    //Testing Searching ALgorithms
    int test[5] = {1,2,3,4,5};
    std::cout << Algorithms::LinearSearch(test, 5, 1) << "\n";
    std::cout << Algorithms::BinarySearch(test, 5, 1) << "\n";
    
}




