#include "queue.h"
template <class elemType>
class linkQueue : public queue<elemType>
{
  private:
    struct node
    {
        elemType data;
        node *next;
        node() : next(nullptr) {}
        node(const elemType &x, node *n = nullptr)
        {
            data = x;
            next = n;
        }
        ~node() {}
    };
    node *front, *rear;

  public:
    linkQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead() const;
    ~linkQueue();
};
template <class elemType>
linkQueue<elemType>::linkQueue()
{
    front =rear= nullptr;
}
template<class elemType>
bool linkQueue<elemType>::isEmpty()const
{
    return front==nullptr;
}
template<class elemType>
void linkQueue<elemType>::enQueue(const elemType &x )
{
    if(rear==nullptr){
        front=rear=new node(x);
    }else{
        rear->next=new node(x);
        rear=rear->next;
    }
}
template<class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp=front;
    elemType value=front->data;
    front=front->next;
    if(front==nullptr){
        rear=nullptr;
    }
    delete tmp;
    return value;

}
template<class elemType>
elemType linkQueue<elemType>::getHead()const
{
    return front->data;
}
template<class elemType>
linkQueue<elemType>::~linkQueue()
{
    node *tmp;
    while(front!=nullptr){
        tmp=front;
        front=front->next;
        delete tmp;
    }
}