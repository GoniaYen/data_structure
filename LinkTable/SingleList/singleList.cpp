#include<iostream>
#include "list.h"
using namespace std;
class OutOfBound{};
class IllegalSize{};
template<class elemType>
class singleList:public list<elemType>{
    private:
        struct node{
            elemType data;
            node *next; 
            node(const elemType &x,node *n=NULL){
                data=x;             
                next=n;
            }
            node():next(NULL){}
            ~node(){}

        };
        node *head;//头指针
        node *h;//头结点
        int currentLength;//表长
        node *move(int i)const;//返回第i个节点的指针

    public:
        singleList();
        ~singleList(){clear();delete head;}

        void clear();
        int length()const;
        void insert(int i,const elemType &x);
        void insertHead(const elemType &x);
        void insertTail(const elemType &x);
        void remove(int i);
        int  search(const elemType &x)const;
        elemType visit(int i)const;
        void traverse() const;
        bool isEmpty()const;
        bool isFull()const;
       
};
template<class elemType>
typename singleList<elemType>::node *singleList<elemType>::move(int i)const{
    node *p = head->next;
    if(i<0||i>currentLength)throw OutOfBound();
    // int j=i-1;
    while(i--)p=p->next;
    return p;
}
template<class elemType> singleList<elemType>::singleList(){
    head=new node;
    h = new node;
    head=h;
    currentLength = 0;
   
}
template<class elemType>
void singleList<elemType>::clear(){
    node *p=head->next,*q;
    while(p!=NULL){
        q=p->next;
        delete p;
        p=q;
    }

}

template<class elemType>
int singleList<elemType>::length()const{
    return 0;
}

template<class elemType>
void singleList<elemType>::insertHead(const elemType &x){
    node *tmp = new node;
    tmp->data=x;
    tmp->next=head->next;
    head->next=tmp;
    ++currentLength;
}
template<class elemType>
void singleList<elemType>::insertTail(const elemType &x)

{
    node *tmp = new node;
    tmp->data=x;
    h->next=tmp;
    h=tmp;
    ++currentLength;

}
template<class elemType>
void singleList<elemType>::insert(int i,const elemType &x){
    node *pos,*temp;
    pos=move(i);
    temp  = new node(x,pos->next);
    pos->next=temp;   
    ++currentLength;
    
}

template<class elemType>
void singleList<elemType>:: remove(int i){
    node *pos;
    pos = move(i-1);
    pos->next=pos->next->next;
    delete pos;
    --currentLength;

}


template<class elemType>
int singleList<elemType>:: search(const elemType &x)const{
    node *p = head->next;
    int i = 0;
    while(p!=NULL && p->data!=x){//定位
        p=p->next;
        ++i;
    }
    if(p==NULL){
        return -1;
    }else{
        return i;
    }
    

}

template<class elemType>
elemType singleList<elemType>:: visit(int i)const
{
    node *p=move(i);
    return p->data;

}
        

template<class elemType>
void singleList<elemType>::traverse() const{
    node *p= head->next;
    cout<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class elemType>
bool singleList<elemType>::isEmpty()const{
    if(currentLength==0){
        return true;
    }else{
        return false;
    }
}
template<class elemType>
bool singleList<elemType>::isFull()const{
    return false;
}

