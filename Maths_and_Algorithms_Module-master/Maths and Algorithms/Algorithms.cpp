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
