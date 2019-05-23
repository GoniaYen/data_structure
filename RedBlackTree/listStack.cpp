#include<iostream>
#include "stack.h"
template <class elemType>
class listStack:public stack<elemType>
{
    private:
        struct node{
            elemType data;
            node *next;
            node(const elemType &x,node *n = NULL){
                data=x;
                next= n;
            }
            node():next(NULL){}
            ~node(){}
            
        };
        node *elem;
    public:
        listStack(){
            elem = NULL; 
        }
        ~listStack(){ 
        }

        bool isEmpty()const{
            return elem==NULL;
        }


        void push(const elemType &x){
            node *tmp = new node(x,elem);
            elem=tmp;
        }
        elemType pop(){
            node *tmp = elem;
            elemType x = tmp->data;
            elem=elem->next;
            delete tmp;
            return x;
        }
        elemType top()const{
            return elem->data;
        }
       
};
