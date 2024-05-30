#include "Algorithms.h"
//Tip from Nick to remember:
//Store what you're returning in a temp variable then return it at the end

//Searches through every value in an array until we find the one we want
int* Algorithms::LinearSearch(int* Data, size_t size, int target)
{
    int* result = nullptr;
    //Loop through every index in our array
    for(int i = 0; i < size ; i++)
    {
        //If current value is the target
        if(Data[i] == target)
        {
            result =  &Data[i]; //Sets result to the memory address of Data[i]
        }
    }

    return result;
}

//Function to calculate midpoint
int midpoint(int min, int max)
{
    return ((max - min) / 2) + min;
}

//Is the data the mid point, or is it greater or lower than it
//Assumes data is already sorted
int* Algorithms::BinarySearch(int* Data, size_t size, int target)
{
    bool found = false;
    int min = 0;
    int max = size - 1;
    int mid = midpoint(min, max);
    int* result = nullptr;

    while(!found)
    {
        //We found it!
        if(target == Data[mid])
        {
            found = true;
            result = &Data[mid];
        }
        //Target is less then midpoint, make current midpoint new max and recalculate midpoint
        else if(target < Data[mid])
        {
            max = mid;
            mid = midpoint(min, max);
        }
        //Target is more then midpoint, make current midpoint new min and recalculate midpoint
        else
        {
            min = mid;
            mid = midpoint(min, max);
        }
    }
    return result; 
}

//This algorithm swaps pairs of values until no swaps are made and the list is sorted
int * Algorithms::BubbleSort(int* Data, size_t size)
{
    int swaps = 1;
    int temp;
    
    //Keeping going through while values are still being swapped
    //If we make no swaps, list is sorted so we can stop
    while(swaps > 0)
    {
        swaps = 0;
        for(int i = 0; i < size - 2; i++) //Size - 2 so we dont try to access a value at an index that doesnt exist
        {
            //If the left value is less than the next value, swap them
            if(Data[i] > Data[i + 1])
            {
                temp = Data[i+1];
                Data[i + 1] = Data[i];
                Data[i] = temp;
                swaps++;
            }
        }
    }
    return Data;
}

//Goes through array inserting values into correct place
int * Algorithms::InsesrtionSort(int* Data, size_t size)
{
    //Variable for previous value in array
    int prev;
    //Loop through the array
    for(int i = 0; i < size; i++)
    {
        int valueToSort = Data[i];
        prev = i - 1; 
        //While the previous value is greater than current, shift to right 
        while(Data[prev] > valueToSort && prev >= 0)
        {
            Data[prev + 1] = Data[prev];
            prev -= 1;
        }
        //After all values greater than valueToSort have been done, put valueToSort in correct place
        Data[prev + 1] = valueToSort;
    }
    return Data;
}

//Grabs first unsorted value, the searches rest of array for next lowest value, and swaps them
int * Algorithms::SelectionSort(int* Data, size_t size)
{
    int minimumIndex;
    for(int i = 0; i < size; i++)
    {
        minimumIndex = i;
        //Find the next minimum value
        for(int j = i + 1; j < size; j++)
        {
            if(Data[j] < Data[minimumIndex])
            {
                minimumIndex = j;
            }
        }
        //We found minimum value, swap with i
        int temp = Data[i];
        Data[i] = Data[minimumIndex];
        Data[minimumIndex] = temp;
    }
    return Data;
}

int * Algorithms::MergeSort(int* Data, size_t size)
{
    if(size <= 2)
    {
        //find biggest, swap them if biggest is 1st
        //then return data
        if(Data[0] > Data[1])
        {
            int temporary = Data[0];
            Data[0] = Data[1];
            Data[1] = temporary;
            return Data;
        }
    }
    
    int mid = size / 2;
    int left[mid];
    int right[mid];
    //Iterates thorugh half of data, adding it to our two new lists
    for(int i = 0; i < mid; i++)
    {
        left[i] = Data[i];
        right[i] = Data[mid+i];
    }

    //Recursively calls merge sort on two halves, merges them together and returns
    int* Sorted1 = MergeSort(left,mid);
    int* Sorted2 = MergeSort(right,mid);
    //now merge two arrays together but sorted and return
    int* Merged = new int[size];
    Merged = MergeArraysSorted(left, mid, right, mid, Merged);
    return Merged;
}

/* Takes two arrays to merge, their sizes and a sorted array
i = how many left array elemnts have been merged
j = how many right array elements have been merged
k = how many total things have been merged*/
int * Algorithms::MergeArraysSorted(int* left, size_t leftSize, int* right, size_t rightSize, int* sorted)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < leftSize && j < rightSize)
    {
        //If left value is less than right, merge it
        if(left[i] < right[j])
        {
            sorted[k++] = left[i++];
        }
        //If right is less than left, add it
        else
        {
            sorted[k++] = right[j++];
        }
    }
    //Add any remaining values in either array 
    while(i < leftSize)
    {
        sorted[k++] = left[i++];
    }

    while(j < rightSize)
    {
        sorted[k++] = right[j++];
    }

    return sorted;
}

//Quick sort :)
int * Algorithms::QuickSort(int* Data, size_t size)
{
    int lowIndex = 0;
    int highIndex = size - 1;
    int pivot = Algorithms::split(Data, lowIndex, highIndex);

    //keep calling quick sort until we get to sub arrays of 2 or 1
    if (lowIndex < pivot - 1)
        QuickSort(Data, pivot - lowIndex);
    if (pivot < highIndex)
        QuickSort(Data + pivot, highIndex - pivot + 1);

    return Data;
}

//Greater than pivot, right. Less than pivot left.
int Algorithms::split(int *Data, int lowIndex, int highIndex)
{
    int pivotIndex = ((highIndex - lowIndex) / 2) + lowIndex;
    int pivotValue = Data[pivotIndex];

    //Scan left side of array until we find a value > pivot value
    while(Data[lowIndex] < pivotValue)
    {
        lowIndex++;
    }
    //Scan right side of array until we find a value < pivot value
    while(Data[highIndex] > pivotValue)
    {
        highIndex--;
    }

    //Swap if needed
    if(lowIndex <= highIndex)
    {
        int temp = Data[lowIndex];
        Data[lowIndex] = Data[highIndex];
        Data[highIndex] = temp;

        //Go onto next pair of values:
        lowIndex++;
        highIndex--;
    }
    
    return lowIndex;
}

int* Algorithms::BinSort(int* Data, size_t size)
{
    int largest = FindLargestVal(Data, size);
    const int numBuckets = 10;
    int interval = (largest + 1) / numBuckets; //Value to determine range of numbers which go into each bucket
    int buckets[numBuckets][size]; //2D array to for buckets
    int bucketAmount[numBuckets]; //Array to hold how many values are in each bucket

    //Set bucket amount for each bucket to zero
    for(int i = 0; i < numBuckets; i++)
    {
        bucketAmount[i] = 0;
    }

    //For loop which goes through Data, calculates which bucket it needs to go into
    //Adds value to buckets 2d Array at in the correct index abd increment bucketAmount index so we know which buckets have values added to 
    for(int i = 0; i < size; i++)
    {
        int bucketIndex = Data[i] / interval;
        buckets[bucketIndex][bucketAmount[bucketIndex]++] = Data[i];
    }
    //Go through each bucket, sorting them and appending them to new sorted array
    int dataIndex = 0; //Index of original data we're checking
    for(int i = 0; i < numBuckets; i++)
    {
        int* inserted = InsesrtionSort(buckets[i], bucketAmount[i]); //Sorts ith bucket
        //New loop to iterate through sorted bucket and append it to orginal (now sorted)
        for(int j = 0; j < bucketAmount[i]; j++)
        {
            Data[dataIndex++] = inserted[j];
        }
    }
    return Data;

}

//Function which checks every value in array to find and return largest value
int Algorithms::FindLargestVal(int* Data, size_t size)
{
    int result = Data[0];
    for(int i = 0; i < size; i++)
    {
        if(Data[i] > result)
        {
            result = Data[i];
        }
    }
    return result;
}