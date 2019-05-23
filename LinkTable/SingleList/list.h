#ifndef __LIST_H__
#define __LIST_H_

template<class elemType> class list{
    public:
        virtual void clear()=0;
        virtual int length()const=0;
        virtual void insert(int i,const elemType &x)=0;
        virtual void remove(int i)=0;
        virtual int  search(const elemType &x)const=0;
        virtual elemType visit(int i)const=0;
        virtual void traverse() const=0;
        virtual bool isEmpty()const=0;
        virtual bool isFull()const=0;
        virtual ~list(){};
};
#endif