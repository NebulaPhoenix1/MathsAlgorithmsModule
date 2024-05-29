#include <iostream>
#include <math.h>
#include <algorithm>

#include "Algorithms.h"
#include "DataStructures.h"
#include "Maths.h"
#include "Matrix.h"
#include "Vector.h"

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

    //Testing multiplying matrices
    std::cout << "Testing Matrices" << "\n";
    Matrix testMatrix;
    testMatrix.Data[0][0] = 1;
    testMatrix.Data[0][1] = 2;
    testMatrix.Data[0][2] = 3;
    testMatrix.Data[1][0] = 4;
    testMatrix.Data[1][1] = 5;
    testMatrix.Data[1][2] = 6;
    testMatrix.Data[2][0] = 7;
    testMatrix.Data[2][1] = 8;
    testMatrix.Data[2][2] = 9;
    
    float cry = testMatrix.Determinate();
    std::cout << cry << "\n";

    Matrix testMatrix2;
    testMatrix2.Data[0][0] = 9;
    testMatrix2.Data[0][1] = 8;
    testMatrix2.Data[0][2] = 7;
    testMatrix2.Data[1][0] = 6;
    testMatrix2.Data[1][1] = 5;
    testMatrix2.Data[1][2] = 4;
    testMatrix2.Data[2][0] = 3;
    testMatrix2.Data[2][1] = 2;
    testMatrix2.Data[2][2] = 1;

    Matrix Result = testMatrix * testMatrix2;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << Result.Data[i][j] << ",";
        }
    }
    std::cout << "\n";
    //testing multiplying vector by matrix
    Vector testVector3(1,0,-1);
    Vector vecRes = testMatrix * testVector3;
    std::cout << vecRes.x;
    std::cout << vecRes.y;
    std::cout << vecRes.z << "\n";
    
    //Testing mathutils
    std::cout<<MathUtils::FindHyp(45,4) << "\n";
    std::cout<<MathUtils::FindAdj(45,4) << "\n";
    std::cout<<MathUtils::FindOpp(45,4) << "\n";

    //Testing Queues/Stacks
    DataStructures::Queue<int> queue;
    queue.Push(10);
    int testing = queue.Peek();
    //std::cout<<testing;

    //Testing Matrix rotate
    Vector rotateMe(1,2,3);
    Matrix rotational;
    rotateMe = rotational.RotateAroundX(rotateMe, 45.0f);
    //std::cout << rotateMe.x << " " << rotateMe.y << " " << rotateMe.z;

    //testing nodes
    DataStructures::Node<int>nodeTestLeft(8); //creates node with no children (sad)
    DataStructures::Node<int>nodeTestright(12);
    DataStructures::Node<int>nodeTest(10, &nodeTestLeft, &nodeTestright); //creates node with 2 children nodes with values 8 and 12
    
    //merging two sorted arrays testing
    int left[3] = {2,4,6};
    int right[3] = {1,3,5};
    int combined[6];
    Algorithms::MergeArraysSorted(left, 3, right, 3, combined);
    for(int i = 0; i < 6; i++)
    {
        std::cout << combined[i];
    }

    //Testing Sorting Algorithms
    int sort[5] = {2,1,6,3,4};
    //int* inserted = Algorithms::InsesrtionSort(sort, 7);
    //int* bubbled = Algorithms::BubbleSort(sort, 7);
    //int* selected = Algorithms::SelectionSort(sort, 7);
    int* merged = Algorithms::MergeSort(sort, 5);
    for(int i = 0; i < 5; i++)
    {
        std::cout << merged[i] << " ";
    }
    std::cout<<"\n";
}