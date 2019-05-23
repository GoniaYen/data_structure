#include <iostream>
#include "queue.h"
#include "linkQueue.cpp"
#include "seqQueue.cpp"
int main()
{
    queue<int> *s = new linkQueue<int>();
   
    int i;
    for(i = 0;i<25;i++){
        s->enQueue(i);
    }

    std::cout<< s->getHead()<<std::endl<<std::endl;
    
    while(!s->isEmpty()){
       std::cout<< s->deQueue()<<std::endl;
    }
    
    
    return 0;
}