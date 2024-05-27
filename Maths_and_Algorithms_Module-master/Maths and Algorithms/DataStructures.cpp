#include "DataStructures.h"

template<typename T>
Stack<T>::Stack()
{
	Data = new T[Size]; //Creates array of type teplate T and reserves size as length
}

//Pop returns and removes first value
template<typename T>
T Stack<T>::Pop()
{
	T popValue = Data[firstIndex];
	Data[firstIndex] = 0;
	firstIndex++;
	return popValue;
}

template<typename T>
T Stack<T>::Peek()
{
	return Data[firstIndex];
}

template<typename T>
void Stack<T>::Push(T dataToPush)
{
	 Data[freeIndex] = dataToPush;
	 freeIndex++;
}

template<typename T>
Queue<T>::Queue()
{
	Data = new T[Size]; //creates array of template T and size of Size.
}

//Remove and return data at queueHead, queueHead++
template<typename T>
T Queue<T>::Pop()
{
	T value = nullptr;
	value = Data[queueHead % Size];
	Data[queueHead % Size] = nullptr;
	queueHead++;
	full = false;
	return value;
}

//Look at next value to pop (does not remove it)
template<typename T>
T Queue<T>::Peek()
{
	return Data[queueHead%Size];
}

template<typename T>
void Queue<T>::Push(T dataToPush)
{
	if(full == false)
	{
		Data[queueTail] = dataToPush;
		queueTail++;
		//Check if queue after pushing is full, if so set full to true so we can't push anymore
		if(queueTail % Size == 0)
		{
			full = true;
		}
	}
}
