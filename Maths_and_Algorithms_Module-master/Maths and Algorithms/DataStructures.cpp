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
	Data[firstIndex] = NULL;
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
