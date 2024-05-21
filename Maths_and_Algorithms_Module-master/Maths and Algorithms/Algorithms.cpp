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
