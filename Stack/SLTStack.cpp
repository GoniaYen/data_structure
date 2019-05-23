#include<iostream>
#include<stack>
#include<list>
#include<vector>
using namespace std;

int main(){
    stack<int,vector<int>>s1;
    stack<int,list<int>>s2;
    int i;
    for(i=0;i<20;i++){
        s1.push(i);
    }

    for(i=100;i<130;i++){
        s2.push(i);
    }
    
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop(); 
    }
    cout<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop(); 
    }
    cout<<endl;

}
