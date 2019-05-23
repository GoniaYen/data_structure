#include<iostream>
#include<vector>
using namespace  std;
void testVector(){
    vector<int>v;
    cout<<"the inital size of v is"<<v.size()<<"\nthe initial capacity of v is"<<v.capacity();
    v.push_back(1);
    cout<<"\n after push 1 capacity of v is "<<v.capacity();
    v.push_back(2);
    cout<<"\n after push 2 capacity of v is "<<v.capacity();
    v.push_back(3);
    cout<<"\n after push 3 capacity of v is "<<v.capacity();//这里输出为4，会出现内存对齐
    v.push_back(4);
    cout<<"\n after push 4 capacity of v is "<<v.capacity();

    cout<<"\nthe  size of v is"<<v.size()<<"\nthe capacity of v is"<<v.capacity()<<endl;
    //用下表访问元素
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //迭代器访问
    vector<int>::const_iterator p;
    for(p=v.begin();p!=v.end();p++){
        cout<<*p<<" ";
    }
    cout<<endl;


}
int main(){
    testVector();
    return 0;
}