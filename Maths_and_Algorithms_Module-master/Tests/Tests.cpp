#include "pch.h"
#include "CppUnitTest.h"
#include "../Maths and Algorithms/Algorithms.h"
#include "../Maths and Algorithms/DataStructures.h"
#include "../Maths and Algorithms/Maths.h"
#include "../Maths and Algorithms/Matrix.h"
#include "../Maths and Algorithms/Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Algorithms)
	{
	public:
		
		TEST_METHOD(StackPushPopTest)
		{
			// Arrange
			Stack<int> stack;
			int dataToPush = 5;

			// Act
			stack.Push(dataToPush);
			int poppedData = stack.Pop();

			// Assert
			Assert::AreEqual(5, poppedData, L"Pop() did not return the expected value");
		}

		TEST_METHOD(StackPeekTest)
		{
			// Arrange
			Stack<int> stack;
			int dataToPush = 5;

			// Act
			stack.Push(dataToPush);
			int peekedData = stack.Peek();

			// Assert
			Assert::AreEqual(5, peekedData, L"Peek() did not return the expected value");
		}

		TEST_METHOD(StackPushMultipleTest)
		{
			// Arrange
			Stack<int> stack;

			// Act
			stack.Push(1);
			stack.Push(2);
			stack.Push(3);

			// Assert
			Assert::AreEqual(3, int(stack.Size), L"Size is incorrect after pushing multiple elements");
		}
		TEST_METHOD(QueuePushPopTest)
		{
			// Arrange
			Queue<int> queue;
			int dataToPush = 5;

			// Act
			queue.Push(dataToPush);
			int poppedData = queue.Pop();

			// Assert
			Assert::AreEqual(5, poppedData, L"Pop() did not return the expected value");
		}

		TEST_METHOD(QueuePeekTest)
		{
			// Arrange
			Queue<int> queue;
			int dataToPush = 5;

			// Act
			queue.Push(dataToPush);
			int peekedData = queue.Peek();

			// Assert
			Assert::AreEqual(5, peekedData, L"Peek() did not return the expected value");
		}

		TEST_METHOD(QueuePushMultipleTest)
		{
			// Arrange
			Queue<int> queue;

			// Act
			queue.Push(1);
			queue.Push(2);
			queue.Push(3);

			// Assert
			Assert::AreEqual(3, int(queue.Size), L"Size is incorrect after pushing multiple elements");
		}

		TEST_METHOD(NodeInitializationTest)
		{
			// Arrange
			int testData = 5;

			// Act
			Node<int>* node = new Node<int>();
			node->Data = testData;

			// Assert
			Assert::AreEqual(testData, node->Data, L"Node data is not initialized correctly");
			Assert::IsNull(node->Left, L"Left child pointer is not initialized correctly");
			Assert::IsNull(node->Right, L"Right child pointer is not initialized correctly");

			// Clean up
			delete node;
		}

		TEST_METHOD(MinHeapAddTest)
		{
			// Arrange
			MinimumBinaryHeap<int> heap;
			int dataToAdd = 5;

			// Act
			heap.Add(dataToAdd);

			// Assert
			Assert::AreEqual(dataToAdd, heap.Root->Data, L"Root data is not initialized correctly after adding");
		}

		TEST_METHOD(MinHeapRemoveTest)
		{
			// Arrange
			MinimumBinaryHeap<int> heap;
			heap.Add(5);
			heap.Add(10);
			heap.Add(7);

			// Act
			int removedData = heap.Remove();

			// Assert
			Assert::AreEqual(5, removedData, L"Remove() did not return the expected value");
			Assert::AreEqual(7, heap.Root->Data, L"Root data is not updated correctly after removal");
		}

	};


	TEST_CLASS(DataStructures)
	{
	public:

		TEST_METHOD(BubbleSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::BubbleSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"BubbleSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"BubbleSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}

		// Similar tests for other sorting functions: InsertionSort, SelectionSort, HeapSort, MergeSort, QuickSort, BinSort

		TEST_METHOD(LinearSearchTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);
			int target = 5;
			// Act
			int* result = ::Algorithms::LinierSearch(testData, size, target);

			// Assert
			// Write assertions to verify the result

			// Clean up
			delete[] result;
		}

		TEST_METHOD(BinarySearchTest)
		{
			// Arrange
			int testData[] = { 1, 3, 5, 7, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);
			int target = 5;

			// Act
			int* result = ::Algorithms::BinarySearch(testData, size, target);

			// Assert
			// Write assertions to verify the result

			// Clean up
			delete[] result;
		}
		TEST_METHOD(InsertionSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::InsesrtionSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"InsertionSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"InsertionSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}

		TEST_METHOD(SelectionSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::SelectionSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"SelectionSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"SelectionSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}

		TEST_METHOD(HeapSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::HeapSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"HeapSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"HeapSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}

		TEST_METHOD(MergeSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::MergeSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"MergeSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"MergeSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}

		TEST_METHOD(QuickSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::QuickSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"QuickSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"QuickSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}

		TEST_METHOD(BinSortTest)
		{
			// Arrange
			int testData[] = { 5, 3, 7, 1, 9 };
			size_t size = sizeof(testData) / sizeof(testData[0]);

			// Act
			int* sortedData = ::Algorithms::BinSort(testData, size);

			// Assert
			Assert::AreEqual(1, sortedData[0], L"BinSort did not sort the array correctly");
			Assert::AreEqual(9, sortedData[size - 1], L"BinSort did not sort the array correctly");

			// Clean up
			delete[] sortedData;
		}
	};
	TEST_CLASS(Maths)
	{
	public:

		TEST_METHOD(DegToRadTest)
		{
			// Arrange
			float degrees = 45.0f;

			// Act
			float radians = MathUtils::toRad(degrees);

			// Assert
			// Verify that the conversion from degrees to radians is correct
			Assert::AreEqual(0.785398163f, radians, 0.0001f, L"Conversion from degrees to radians is incorrect");
		}

		TEST_METHOD(RadToDegTest)
		{
			// Arrange
			float radians = 0.785398163f;

			// Act
			float degrees = MathUtils::toDeg(radians);

			// Assert
			// Verify that the conversion from radians to degrees is correct
			Assert::AreEqual(45.0f, degrees, 0.0001f, L"Conversion from radians to degrees is incorrect");
		}
		TEST_METHOD(PythagorasTest)
		{
			// Arrange
			float sideA = 3.0f;
			float sideB = 4.0f;

			// Act
			float hypotenuse = MathUtils::Pythagoras(sideA, sideB);

			// Assert
			// Verify that the calculation of the hypotenuse is correct
			Assert::AreEqual(5.0f, hypotenuse, 0.0001f, L"Calculation of hypotenuse is incorrect");
		}
		TEST_METHOD(FindSinThetaTest)
		{
			// Arrange
			float sideA = 3.0f;
			float sideB = 4.0f;

			// Act
			float sinTheta = MathUtils::FindSinTheta(sideA, sideB);

			// Assert
			// Verify that the calculation of sine theta is correct
			Assert::AreEqual(0.6f, sinTheta, 0.0001f, L"Calculation of sine theta is incorrect");
		}

		TEST_METHOD(FindCosThetaTest)
		{
			// Arrange
			float sideA = 3.0f;
			float sideB = 4.0f;

			// Act
			float cosTheta = MathUtils::FindCosTheta(sideA, sideB);

			// Assert
			// Verify that the calculation of cosine theta is correct
			Assert::AreEqual(0.8f, cosTheta, 0.0001f, L"Calculation of cosine theta is incorrect");
		}

		TEST_METHOD(FindTanThetaTest)
		{
			// Arrange
			float sideA = 3.0f;
			float sideB = 4.0f;

			// Act
			float tanTheta = MathUtils::FindTanTheta(sideA, sideB);

			// Assert
			// Verify that the calculation of tangent theta is correct
			Assert::AreEqual(0.75f, tanTheta, 0.0001f, L"Calculation of tangent theta is incorrect");
		}
		TEST_METHOD(FindHypTest)
		{
			// Arrange
			float angle = 45.0f;
			float sideB = 4.0f;

			// Act
			float hypotenuse = MathUtils::FindHyp(angle, sideB);

			// Assert
			// Verify that the calculation of hypotenuse is correct
			Assert::AreEqual(5.65685f, hypotenuse, 0.0001f, L"Calculation of hypotenuse is incorrect");
		}

		TEST_METHOD(FindOppTest)
		{
			// Arrange
			float angle = 45.0f;
			float sideB = 4.0f;

			// Act
			float opposite = MathUtils::FindOpp(angle, sideB);

			// Assert
			// Verify that the calculation of opposite side is correct
			Assert::AreEqual(4.0f, opposite, 0.0001f, L"Calculation of opposite side is incorrect");
		}

		TEST_METHOD(FindAdjTest)
		{
			// Arrange
			float angle = 45.0f;
			float sideB = 4.0f;

			// Act
			float adjacent = MathUtils::FindAdj(angle, sideB);

			// Assert
			// Verify that the calculation of adjacent side is correct
			Assert::AreEqual(4.0f, adjacent, 0.0001f, L"Calculation of adjacent side is incorrect");
		}
	};

	TEST_CLASS(Vectors)
	{
	public:

		TEST_METHOD(CrossProductTest)
		{
			// Arrange
			Vector vectorA(1.0, 2.0, 3.0);
			Vector vectorB(4.0, 5.0, 6.0);
			Vector expectedCrossProduct(-3.0, 6.0, -3.0);

			// Act
			Vector crossProduct = vectorA.Cross(vectorB);

			// Assert
			Assert::AreEqual(expectedCrossProduct.x, crossProduct.x, L"X component is incorrect");
			Assert::AreEqual(expectedCrossProduct.y, crossProduct.y, L"Y component is incorrect");
			Assert::AreEqual(expectedCrossProduct.z, crossProduct.z, L"Z component is incorrect");
		}
		TEST_METHOD(MagnitudeTest)
		{
			// Arrange
			Vector vector(3.0f, 4.0f, 0.0f); // A 3-4-5 right triangle
			float expectedMagnitude = 5.0f;

			// Act
			float magnitude = vector.Magnitude();

			// Assert
			Assert::AreEqual(expectedMagnitude, magnitude, 0.0001f, L"Magnitude is incorrect");
		}
		TEST_METHOD(NormaliseTest)
		{
			// Arrange
			Vector vector(3.0f, 4.0f, 0.0f); // A vector with magnitude 5
			Vector expectedNormalizedVector(0.6f, 0.8f, 0.0f); // Normalized vector with magnitude 1

			// Act
			vector.Normalise();

			// Assert
			Assert::AreEqual(expectedNormalizedVector.x, vector.x, 0.0001f, L"X component is incorrect");
			Assert::AreEqual(expectedNormalizedVector.y, vector.y, 0.0001f, L"Y component is incorrect");
			Assert::AreEqual(expectedNormalizedVector.z, vector.z, 0.0001f, L"Z component is incorrect");
		}

		TEST_METHOD(ScaleTest)
		{
			// Arrange
			Vector vector(3.0f, 4.0f, 2.0f); // A vector with initial components
			float scaler = 2.0f; // Scaling factor
			Vector expectedScaledVector(6.0f, 8.0f, 4.0f); // Expected scaled vector

			// Act
			vector.Scale(scaler);

			// Assert
			Assert::AreEqual(expectedScaledVector.x, vector.x, 0.0001f, L"X component is incorrect");
			Assert::AreEqual(expectedScaledVector.y, vector.y, 0.0001f, L"Y component is incorrect");
			Assert::AreEqual(expectedScaledVector.z, vector.z, 0.0001f, L"Z component is incorrect");
		}
		TEST_METHOD(DotProductTest)
		{
			// Arrange
			Vector vectorA(1.0f, 2.0f, 3.0f);
			Vector vectorB(4.0f, 5.0f, 6.0f);
			float expectedDotProduct = 32.0f; // Expected dot product of the two vectors

			// Act
			float dotProduct = vectorA.Dot(vectorB);

			// Assert
			Assert::AreEqual(expectedDotProduct, dotProduct, 0.0001f, L"Dot product is incorrect");
		}

	};
	TEST_CLASS(Matrices)
	{
	public:

		TEST_METHOD(DeterminateTest)
		{
			// Arrange
			Matrix matrix;
			// Fill in matrix with appropriate values

			matrix.Data[0][0] = 1.0f;
			matrix.Data[0][1] = 2.0f;
			matrix.Data[0][2] = 3.0f;
			matrix.Data[1][0] = 4.0f;
			matrix.Data[1][1] = 5.0f;
			matrix.Data[1][2] = 6.0f;
			matrix.Data[2][0] = 7.0f;
			matrix.Data[2][1] = 8.0f;
			matrix.Data[2][2] = 9.0f;

			// Calculate the expected determinant manually
			// Calculate the expected determinant manually
			float expectedDeterminant = 0;


			// Act
			float det = matrix.Determinate();

			// Assert
			Assert::AreEqual(expectedDeterminant, det, 0.0001f, L"Determinant is incorrect");
		}

		TEST_METHOD(RotateAroundXTest)
		{
			// Arrange
			Matrix matrix;
			// Fill in matrix with appropriate values
			float angle = 45.0f; // Example angle
			matrix.Data[0][0] = 1.0f;
			matrix.Data[0][1] = 0.0f;
			matrix.Data[0][2] = 1.0f;
			
			matrix.Data[1][0] = 0.0f;
			matrix.Data[1][1] = 1.0f;
			matrix.Data[1][2] = 0.0f;
			
			matrix.Data[2][0] = 1.0f;
			matrix.Data[2][1] = 1.0f;
			matrix.Data[2][2] = 1.0f;

			// Act
			matrix.RotateAroundX(angle);

			Assert::AreEqual(matrix.Data[1][1], 0.707f, 0.0001f, L"Rotated element is incorrect");
			Assert::AreEqual(matrix.Data[1][2], 0.293f, 0.0001f, L"Rotated element is incorrect");

			Assert::AreEqual(matrix.Data[2][1], 0.707f, 0.0001f, L"Rotated element is incorrect");
			Assert::AreEqual(matrix.Data[2][2], 1.707f, 0.0001f, L"Rotated element is incorrect");
		}

		TEST_METHOD(RotateAroundYTest)
		{
			// Arrange
			Matrix matrix;
			// Fill in matrix with appropriate values
			float angle = 45.0f; // Example angle

			matrix.Data[0][0] = 1.0f;
			matrix.Data[0][1] = 0.0f;
			matrix.Data[0][2] = 1.0f;

			matrix.Data[1][0] = 0.0f;
			matrix.Data[1][1] = 1.0f;
			matrix.Data[1][2] = 0.0f;

			matrix.Data[2][0] = 1.0f;
			matrix.Data[2][1] = 1.0f;
			matrix.Data[2][2] = 1.0f;

			// Act
			matrix.RotateAroundY(angle);

			// Assert
			// Verify that the matrix is rotated correctly
			// You may need to manually calculate the expected values
			// or use known test cases to verify the rotation

			Assert::AreEqual(matrix.Data[0][0], 1.0f, 0.0001f, L"Rotated element is incorrect");
			Assert::AreEqual(matrix.Data[0][2], 1.707f, 0.0001f, L"Rotated element is incorrect");

			Assert::AreEqual(matrix.Data[2][0], -1.0f, 0.0001f, L"Rotated element is incorrect");
			Assert::AreEqual(matrix.Data[2][2], 0.707f, 0.0001f, L"Rotated element is incorrect");
		}

		TEST_METHOD(RotateAroundZTest)
		{
			// Arrange
			Matrix matrix;
			// Fill in matrix with appropriate values
			float angle = 45.0f; // Example angle

			matrix.Data[0][0] = 1.0f;
			matrix.Data[0][1] = 0.0f;
			matrix.Data[0][2] = 1.0f;

			matrix.Data[1][0] = 0.0f;
			matrix.Data[1][1] = 1.0f;
			matrix.Data[1][2] = 0.0f;

			matrix.Data[2][0] = 1.0f;
			matrix.Data[2][1] = 1.0f;
			matrix.Data[2][2] = 1.0f;

			// Act
			matrix.RotateAroundZ(angle);

			// Assert
			// Verify that the matrix is rotated correctly
			// You may need to manually calculate the expected values
			// or use known test cases to verify the rotation

			Assert::AreEqual(matrix.Data[0][0], 1.0f, 0.0001f, L"Rotated element is incorrect");
			Assert::AreEqual(matrix.Data[0][1], 0.0f, 0.0001f, L"Rotated element is incorrect");

			Assert::AreEqual(matrix.Data[1][0], 0.0f, 0.0001f, L"Rotated element is incorrect");
			Assert::AreEqual(matrix.Data[1][1], 1.0f, 0.0001f, L"Rotated element is incorrect");
		}

		TEST_METHOD(TranslateTest)
		{
			// Arrange
			Matrix matrix;
			matrix.Data[0][0] = 1.0f;
			matrix.Data[0][1] = 0.0f;
			matrix.Data[0][2] = 1.0f;

			matrix.Data[1][0] = 0.0f;
			matrix.Data[1][1] = 1.0f;
			matrix.Data[1][2] = 0.0f;

			matrix.Data[2][0] = 1.0f;
			matrix.Data[2][1] = 1.0f;
			matrix.Data[2][2] = 1.0f;
			Vector delta(1.0f, 2.0f, 3.0f); // Example translation vector

			// Act
			matrix.Translate(delta);

			Assert::AreEqual(matrix.Data[0][2], 2.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[1][2], 3.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][2], 4.0f, 0.0001f, L"Translate element is incorrect");
		}

		TEST_METHOD(RotateAroundXTest)
		{
			// Arrange
			Matrix matrix;
			// Initialize the matrix with the given values
			matrix.SetMatrix({ {1, 0, 1}, {0, 1, 1}, {0, 0, 1} });

			Vector point(1.0f, 2.0f, 0.0f); // Modified point
			float angle = 45.0f; // Example angle

			// Act
			matrix.RotateAroundX(point, angle);

			// Assert
			Assert::AreEqual(matrix.Data[1][1], 0.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[1][2], 1.707f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][1], -1.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][2], 0.707f, 0.0001f, L"Translate element is incorrect");
		}

		TEST_METHOD(RotateAroundYTest)
		{
			// Arrange
			Matrix matrix;
			// Initialize the matrix with the given values
			matrix.SetMatrix({ {1, 0, 1}, {0, 1, 1}, {0, 0, 1} });

			Vector point(1.0f, 2.0f, 0.0f); // Modified point
			float angle = 45.0f; // Example angle

			// Act
			matrix.RotateAroundY(point, angle);

			// Assert
			Assert::AreEqual(matrix.Data[0][2], 0.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[1][2], 1.414f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][1], 0.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][2], 1.0f, 0.0001f, L"Translate element is incorrect");
		}

		TEST_METHOD(RotateAroundZTest)
		{
			// Arrange
			Matrix matrix;
			// Initialize the matrix with the given values
			matrix.SetMatrix({ {1, 0, 1}, {0, 1, 1}, {0, 0, 1} });

			Vector point(1.0f, 2.0f, 0.0f); // Modified point
			float angle = 45.0f; // Example angle

			// Act
			matrix.RotateAroundZ(point, angle);

			// Assert
			Assert::AreEqual(matrix.Data[0][0], 0.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[0][1], 1.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][0], -1.0f, 0.0001f, L"Translate element is incorrect");
			Assert::AreEqual(matrix.Data[2][1], 0.0f, 0.0001f, L"Translate element is incorrect");
		}

		TEST_METHOD(MatrixMultiplicationTest)
		{
			// Arrange
			Matrix matrix1;
			// Initialize matrix1 with some values
			matrix1.SetMatrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });

			Matrix matrix2;
			// Initialize matrix2 with some values
			matrix2.SetMatrix({ {9, 8, 7}, {6, 5, 4}, {3, 2, 1} });

			// Act
			Matrix result = matrix1 * matrix2;

			// Assert
			Assert::AreEqual(result.Data[0][0], 30, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[0][1], 24, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[0][2], 18, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[1][0], 84, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[1][1], 69, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[1][2], 54, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[2][0], 138, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[2][1], 114, 0.0001f, L"multiplication of matraces is incorrect");
			Assert::AreEqual(result.Data[2][2], 90, 0.0001f, L"multiplication of matraces is incorrect");
		}
	};
}
