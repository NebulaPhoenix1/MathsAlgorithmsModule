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
	 int * MergeSortHelper(int* Data, size_t Size);
	 int * QuickSort(int* Data, size_t Size);
	 int * BinSort(int* Data, size_t Size);

     int * LinearSearch(int* Data, size_t Size, int target);
     int * BinarySearch(int* Data, size_t Size, int target);
}

