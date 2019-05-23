#include <iostream>
#include "sequenceStack.cpp"
using namespace std;
void testSeqStack(){
    seqStack<int> ss(20);
    for(int i =0;i<20;i++){
        ss.push(i);
    }
    do{
        cout<<ss.pop()<<" ";
    }while(!ss.isEmpty());
    
}
void testListStack(){
    seqStack<int> ss(20);
    for(int i =0;i<20;i++){
        ss.push(i);
    }
    do{
        cout<<ss.pop()<<" ";
    }while(!ss.isEmpty());
    
}
int main(){
    //testSeqStack();
    testListStack();
    cout<<endl;
    return 0;
}