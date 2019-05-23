#include<iostream>
#include "stack.h"
template <class elemType>
class seqStack:public stack<elemType>
{
    private:
        elemType *elem;
        int top_p;
        int maxSize;

        void doubleSpace();
    public:
        seqStack(int initSize=10){
            elem=new elemType[initSize];
            maxSize=initSize;
            top_p=-1;
        }
        ~seqStack(){
            delete[] elem;
        }

        bool isEmpty()const{
            return top_p==-1;
        }


        void push(const elemType &x){
            if(top_p==maxSize-1)doubleSpace();
            elem[++top_p]=x;
        }
        elemType pop(){
            return elem[top_p--];
        }
        elemType top()const{
            return elem[top_p];
        }
       
};
template<class elemType>
void seqStack<elemType>::doubleSpace(){
    elemType* temp = elem;

    maxSize *=2;
    elem = new elemType[maxSize];
    
    for(int i =0;i<maxSize;++i)elem[i]=temp[i];
    delete []temp;
}