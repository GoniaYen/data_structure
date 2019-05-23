#include<iostream>
#include<queue>
#include<list>
using namespace std;
int main()
{
    queue<int,list<int>>q1;
    queue<int,deque<int>>q2;
    int i;
    for( i = 0; i < 10; i++)
    {
        q1.push(i);
    }
    while (!q1.empty()){
        cout<<q1.front()<<endl;
        q1.pop();
    }
    for( i = 100; i < 110; i++)
    {
        q2.push(i);
    }
    while (!q2.empty()){
        cout<<q2.front()<<endl;
        q2.pop();
    }
    
    return 0;
}