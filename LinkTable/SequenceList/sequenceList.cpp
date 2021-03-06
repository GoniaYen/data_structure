#include<iostream>
#include "list.h"
using namespace std;
class OutOfBound{};
class IllegalSize{};

template<class elemType>
class seqList:public list<elemType> {
    private:
        elemType *data;
        int currentLength=0;
        int maxSize=0;
        
        void doubleSpace();
    public:
        seqList(int initSize=10); 
        ~seqList(){delete []data;}
        void clear();
        int length()const;
        void insert(int i,const elemType &x);
        void remove(int i);
        int search(const elemType &x)const;
        elemType visit(int i)const;
        void traverse()const;
        bool isEmpty()const;
        bool isFull()const;
       
};
template<class elemType>
void seqList<elemType>::doubleSpace(){
    elemType* temp = data;

    maxSize *=2;
    data = new elemType[maxSize];
    
    for(int i =0;i<currentLength;++i)data[i]=temp[i];
    delete []temp;
}
template<class elemType>
seqList<elemType>::seqList(int initSize){
    if(initSize<=0)throw IllegalSize();
    data = new elemType[initSize];
    maxSize=initSize;
    currentLength=0;
}
template<class elemType>
void seqList<elemType>::insert(int i,const elemType &x){
    if(i<0||i>currentLength)throw OutOfBound();
    if(currentLength>maxSize)doubleSpace();
    for(int j=currentLength;j>i;j--)
        data[j]=data[j-1];
    data[i]=x;
    ++currentLength;
 
}
template<class elemType>
void seqList<elemType>::traverse()const
{
    for(int i=0;i<currentLength;++i)
        cout<<data[i]<<" ";
}
template<class elemType>
void seqList<elemType>::remove(int i){
    if(i<0||i>currentLength-1)throw OutOfBound();
    for(int j =i;j<currentLength-1;j++)data[j]=data[j+1];
    --currentLength;
}
template<class elemType>
int seqList<elemType>::search(const elemType &x)const{
    for(int i=0;i<=currentLength;++i){
        if(data[i]==x){
            return i;
        }
        if(i==currentLength){  
            return -1;
        }
    }
}
template<class elemType>
int seqList<elemType>::length()const{
    return currentLength;
}
template<class elemType>
elemType seqList<elemType>::visit(int i)const{
    if(i<0||i>currentLength-1)throw OutOfBound();
    return data[i];
}
template<class elemType>
void seqList<elemType>::clear(){
    currentLength=0;
    delete []data;
}
template<class elemType>
bool seqList<elemType>::isEmpty()const{
    if(currentLength==0){
        return true;
    }else{
        return false;
    }
}
template<class elemType>
bool seqList<elemType>::isFull()const{
    if(currentLength==maxSize){
        return true;
    }else{
        return false;
    }
}
