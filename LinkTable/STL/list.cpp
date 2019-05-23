#include<iostream>
#include<list> //类似于双链表
using namespace  std;
template<class object>
void printAll(const list<object> &l);
void testList();


int main(){
    testList();
    return 0;
}
void testList(){
    list<int>l;
    l.push_front(1);l.push_front(2);
    l.push_back(3);l.push_back(4);
    printAll(l);

    list<int>::iterator itrs=l.begin(),itre=l.end();
    for(int i = 5; itrs!=itre;++itrs,++i){
        l.insert(itrs,i);
    }
    printAll(l);
    
}
template<class object>
void printAll(const list<object> &l){
    if(l.empty()){
        cout<<"\n list is empty!";
    }else{
        typename list<object>::const_iterator itrs=l.begin(),itre=l.end();
        do{
            cout<<*itrs<<" ";
            ++itrs;
        }while(itrs!=itre);
    }
    cout<<endl;
}