#include <iostream>
#include <queue>
using namespace std;

int main(int argc,char **argv)
{
    priority_queue<int,vector<int>,greater<int>>q;

    q.push(2);
    q.push(5);
    q.push(23);
    q.push(4);
    q.push(6);
    q.push(12);
    q.push(89);
    q.push(202);
    q.push(32);
    q.push(92);
    q.push(88);
    q.push(56);

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    
    return 0;
}