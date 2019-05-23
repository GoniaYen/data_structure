#include<iostream>
#include "singleList.cpp"
int main(){
    singleList<int> sl;
     sl.insertTail(2);
     sl.insertTail(1);
     sl.insertTail(3);
     sl.insertTail(4);

     sl.insertHead(666);
     sl.insertHead(777);

     sl.insert(1,233);

     sl.traverse();
   
   
    cout<<sl.search(233)<<" "<< sl.search(22)<<endl;
    return 0;
}