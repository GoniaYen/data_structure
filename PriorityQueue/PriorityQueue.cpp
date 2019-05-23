#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__
#include <iostream>

using namespace std;
template <class Type>
class PriorityQueue
{
  private:
    int currentSize;
    int maxSize;
    Type *array;

    void buildHeap();
    void doubleSpace();
    void percolateDown(int hole);

  public:
    PriorityQueue(int capacity = 100);
    PriorityQueue(const Type data[], int size);
    ~PriorityQueue();
    bool isEmpty() const;
    void enQueue(const Type &x);
    Type deQueue();
    Type getHead() const;
};
template <class Type>
PriorityQueue<Type>::PriorityQueue(int capacity)
{
    array = new Type[capacity];
    currentSize = 0;
    maxSize = capacity;
}
template <class Type>
PriorityQueue<Type>::PriorityQueue(const Type data[], int size) : maxSize(size + 10), currentSize(size)
{
    array = new Type[maxSize];
    for (int i = 0; i < size; i++)
    {
        array[i + 1] = data[i];
    }
    buildHeap();
}
template <class Type>
PriorityQueue<Type>::~PriorityQueue()
{
    delete[] array;
}
template <class Type>
bool PriorityQueue<Type>::isEmpty() const
{
    return currentSize == 0;
}
template <class Type>
void PriorityQueue<Type>::enQueue(const Type &x)
{
    if (currentSize == maxSize - 1)
    {
        doubleSpace();
        cout << " doubleSpace" << endl;
    }
    //向上过滤
    int hole = ++currentSize;

    for (; hole > 1 && x < array[hole / 2]; hole /= 2)
    {
        array[hole] = array[hole / 2];
       
    }
    array[hole] = x;
}
template <class Type>
Type PriorityQueue<Type>::deQueue()
{
    Type miniItem;
    miniItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
    return miniItem;
}
template <class Type>
Type PriorityQueue<Type>::getHead() const
{
    return array[1];
}
template <class Type>
void PriorityQueue<Type>::buildHeap()
{
    for (int i = currentSize / 2; i > 0; i--)
    {
        percolateDown(i);
    }
}
template <class Type>
void PriorityQueue<Type>::doubleSpace()
{
    Type *temp = array;

    maxSize *= 2;
    array = new Type[maxSize];

    for (int i = 0; i < currentSize; ++i)
        array[i] = temp[i];
    delete[] temp;
}
template <class Type>
void PriorityQueue<Type>::percolateDown(int hole)
{
    int child = hole;
    Type tmp = array[hole];
    for (; hole * 2 <= currentSize; hole = child)
    {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
        {
            child++;
        }
        if (array[child] < tmp)
        {
            array[hole] = array[child];
        }
        else
        {
            break;
        }
    }
    array[hole] = tmp;
}

#endif