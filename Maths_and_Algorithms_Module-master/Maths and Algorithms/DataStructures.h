#pragma once
#include <ctype.h>

//Im fully aware putting definitions in a header file is bad practice
//But the cpp was gaslighting me and not working D:

namespace DataStructures{
template <typename T>
class Stack
{
public:
    Stack()
    {
        Data = new T[Size]; //Creates array of type teplate T and reserves size as length
    }
    T* Data;
    size_t Size;

    int freeIndex = 0; //Next index in our array where we can add data
    int firstIndex = 0; //First index with data stored in it
    
    //Pop returns and removes first value
    T Pop()
    {
        T popValue = Data[firstIndex];
        Data[firstIndex] = 0;
        firstIndex++;
        return popValue;
    }

    //Look at next value to pop (does not remove it)
    T Peek()
    {
        return Data[firstIndex];
    }
    void Push(T dataToPush)
    {
        Data[freeIndex] = dataToPush;
        freeIndex++;
    }
};

template <typename T>
class Queue
{
public:
    Queue()
    {
        Data = new T[Size]; //creates array of template T and size of Size.
    }
    T* Data;
    size_t Size;

    //Remove and return data at queueHead, queueHead++
    T Pop()
    {
        T value = nullptr;
        value = Data[queueHead % Size];
        Data[queueHead % Size] = nullptr;
        queueHead++;
        full = false;
        return value;
    }

    //Look at next value to pop (does not remove it)
    T Peek()
    {
        return Data[queueHead%Size];
    }

    void Push(T dataToPush)
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

    int queueHead = 0; //Where to read data from
    int queueTail = 0; //Where to add data to
    bool full = false;
};


template <typename T>
struct Node
{
    T Data;

    Node* Left;
    Node* Right;

    //Constructor which if left blank, sets child nodes to nullptr
    Node(T Data, Node* Left = nullptr, Node* Right = nullptr) : Data(Data), Left(Left), Right(Right){};
};

template <typename T>
class MinimumBinaryHeap
{

public:
    MinimumBinaryHeap(Node<T>* Root) : Root(Root){}; //Constructor

    Node<T>* Root; //this node should always be the smallest in the tree

    void Add(T DataToAdd); //adds a value to the heap
    T Remove(); //removes smallest value

    void HeapifyUp(); //bubble Up
    void HeapifyDown(); //Bubble Down;
};

}

