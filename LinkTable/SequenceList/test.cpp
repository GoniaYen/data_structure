#include<iostream>
#include "sequenceList.cpp"
using namespace std;

int main(){
    seqList<int>obj(20);
    for(int i=0;i<20;i++){
         obj.insert(i,i+1);
     }

    obj.traverse();
    cout<<endl;
    int a=obj.search(3);
    int c=obj.search(10);
    int b=obj.search(11);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<obj.length()<<endl;
    cout<<obj.visit(3)<<endl;

    
    cout<<obj.length()<<endl;
    obj.traverse();
    // obj.clear();
    cout<<endl;
    cout<<obj.isFull()<<endl;
    cout<<obj.isEmpty()<<endl;

   
    return 0;

}