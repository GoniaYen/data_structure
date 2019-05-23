#include <iostream>
#include "RedBlackTree.cpp"

using namespace std;

int main(int argc,char **argv)
{
    RedBlackTree<int>rbt;
    int a[] = {10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};

  
    for(int i = 0; i < 17; i++)
    {
        rbt.insert(a[i]);
    }
    cout<<"find 2 is"<<(rbt.find(2)?" true":" false")<<endl;

    rbt.remove(2);
    cout<<"find 2 is"<<(rbt.find(2)?" true":" false")<<endl;
    


    return 0;
}