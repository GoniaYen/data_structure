#include<iostream>
#include "list.h"
using namespace std;
class OutOfBound{};
class IllegalSize{};
template<class elemType>
class doubleList:public list<elemType>{
    private:
        struct node{
            elemType data;
            node *prev,*next; 
            node(const elemType &x,node *p=NULL,node *n=NULL){
                data=x;
                prev=p;
                next=n;
            }
            node():prev(NULL),next(NULL){}
            ~node(){}

        };
        node *head,*tail;//头，尾指针
        int currentLength;//表长
        node *move(int i)const;//返回第i个节点的指针

    public:
        doubleList();
        ~doubleList(){clear();delete head;delete tail;}

        void clear();
        int length()const;
        void insert(int i,const elemType &x);
        void remove(int i);
        int  search(const elemType &x)const;
        elemType visit(int i)const;
        void traverse() const;
        bool isEmpty()const;
        bool isFull()const;
       
};
template<class elemType>
typename doubleList<elemType>::node *doubleList<elemType>::move(int i)const{
    node *p = head->next;
    if(i<0||i>currentLength)throw OutOfBound();
    while(i--)p=p->next;
    return p;
}
template<class elemType>
doubleList<elemType>::doubleList(){
    head=new node;
    head->next=tail=new node;
    tail->prev=head;
    currentLength=0;
}
template<class elemType>
void doubleList<elemType>::clear(){

    node *p=head->next,*q;
    head->next=tail;
    tail->prev=head;

    while(p!=tail){
        q=p->next;
        delete p;
        p=q;
    }

}

template<class elemType>
int doubleList<elemType>::length()const{
    return 0;
}


template<class elemType>
void doubleList<elemType>::insert(int i,const elemType &x){
    node *pos,*temp;
    pos=move(i);
    temp  = new node(x,pos->prev,pos);
    pos->prev->next=temp;
    pos->prev=temp;
    ++currentLength;

}

template<class elemType>
void doubleList<elemType>:: remove(int i){
    node *pos;
    pos = move(i);
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;

    delete pos;
    --currentLength;

}


template<class elemType>
int doubleList<elemType>:: search(const elemType &x)const{
    node *p = head->next;
    int i = 0;
    while(p!=tail && p->data!=x){//定位
        p=p->next;
        ++i;
    }
    if(p==tail){
        return -1;
    }else{
        return i;
    }
    

}

template<class elemType>
elemType doubleList<elemType>:: visit(int i)const
{
    node *p=move(i);
    return p->data;

}
        

template<class elemType>
void doubleList<elemType>::traverse() const{
    node *p= head->next;
    cout<<endl;
    while(p!=tail){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<class elemType>
bool doubleList<elemType>::isEmpty()const{
    if(currentLength==0){
        return true;
    }else{
        return false;
    }
}
template<class elemType>
bool doubleList<elemType>::isFull()const{
    return false;
}

