#include<iostream>
#include "queue.h"
template<class elemType>
class seqQueue : public queue< elemType >
{
private:
    elemType *elem;
    int maxSize;
    int front,rear;
    void doubleSpace();
public:
    seqQueue(int size=10);
    bool isEmpty()const;
    void enQueue(const elemType &x );
    elemType deQueue();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    elemType getHead()const;
    ~seqQueue(){delete[] elem;}
};
template<class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    elem = new elemType[size];
    front = rear;
    maxSize = size;

   
}
template<class elemType>
bool seqQueue<elemType>::isEmpty()const
{
    return front==rear;
}
template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &x )
{
    if((rear+1) % maxSize==front){
        doubleSpace();
        
    }
    
    rear = (rear+1)%maxSize;
    elem[rear]=x;

}
template<class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front+1) % maxSize;
    return elem[front];

}
template<class elemType>
elemType seqQueue<elemType>::getHead()const
{
    return elem[(front+1)%maxSize];
}

template<class elemType>
void seqQueue<elemType>::doubleSpace()
{

    elemType* temp = elem;
    elem = new elemType[maxSize*2];
    for(int i =0;i<maxSize;++i){ 
        elem[i]=temp[(front+i)%maxSize];
    }

    maxSize *=2;
     
    
    delete []temp;
}



