#pragma once

//Fixes MacOS by changing size_t to an int.
#ifdef __APPLE__ 
	#define size_t int
#endif

namespace Algorithms
{
	 int * BubbleSort(int* Data, size_t Size);
	 int * InsesrtionSort(int* Data, size_t Size);
	 int * SelectionSort(int* Data, size_t Size);
	 int * HeapSort(int* Data, size_t Size);

	 int * MergeSort(int* Data, size_t Size);
	 int * MergeArraysSorted(int* one, size_t leftSize,int* two, size_t rightSize, int* sorted);

	 int * QuickSort(int* Data, size_t Size);
	 int split(int* Data, int lowIndex, int highIndex);

	 int * BinSort(int* Data, size_t Size);
	 int FindLargestVal(int* Data, size_t size);

     int * LinearSearch(int* Data, size_t Size, int target);
     int * BinarySearch(int* Data, size_t Size, int target);
}

