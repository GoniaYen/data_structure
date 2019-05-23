#include <iostream>
#include "doubleList.cpp"
using namespace std;
int main(){
    doubleList<int>dl;
    for(int i = 0; i < 20; i++)
    {
        dl.insert(i,i+1);
    }
    dl.traverse();
    dl.remove(5);
    dl.traverse();
   dl.insert(19,34);
    dl.traverse();
   
    cout<<dl.search(10)<<" "<< dl.search(22)<<endl;
    return 0;
}