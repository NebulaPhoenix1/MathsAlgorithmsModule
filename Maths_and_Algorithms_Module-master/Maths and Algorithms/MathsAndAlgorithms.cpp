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
    
    //Stacks
    //Stack<int> newStack;

    //Testing Searching ALgorithms
    int test[5] = {1,2,3,4,5};
    std::cout << Algorithms::LinearSearch(test, 5, 1) << "\n";
    std::cout << Algorithms::BinarySearch(test, 5, 1) << "\n";
    
    //vector
    Vector testVector(1,2,3);
    Vector testVector2(4,5,6);
    //testVector.Normalise();
    Vector crossed = testVector.Cross(testVector2);
    std::cout << crossed.x << " " << crossed.y << " " << crossed.z << "\n";
    std::cout << testVector.x << "\n";
    std::cout << testVector.y << "\n";

}




