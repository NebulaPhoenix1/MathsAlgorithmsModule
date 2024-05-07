#pragma once
#include <ctype.h>

template <typename T>
class Stack
{
public:
    Stack();
    T* Data;
    size_t Size;

    int freeIndex = 0; //Next index in our array where we can add data
    int firstIndex = 0; //First index with data stored in it
    
    T Pop();
    T Peek();
    void Push(T dataToPush);
};

template <typename T>
class Queue
{
public:

    T* Data;
    size_t Size;

    T Pop();
    T Peek();
    void Push(T dataToPush);
};


template <typename T>
struct Node
{
    T Data;

    Node* Left;
    Node* Right;
};

template <typename T>
class MinimumBinaryHeap
{

public:
    Node<T>* Root;

    void Add(T DataToAdd);
    T Remove();

    void HeapifyUp(); //bubble Up
    void HeapifyDown(); //Bubble Down;
};



