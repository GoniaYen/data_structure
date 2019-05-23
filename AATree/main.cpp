#include <iostream>
#include "AATree.cpp"

using namespace std;

int main(int argc,char **argv)
{
    AATree<int>aat;
     int a[] = {10,8,6,21,87,56,4,0,11,3,22,7,5,34,1,2,9};

    aat.insert(3);
    aat.insert(2);
    aat.insert(1);
    aat.insert(4);
    aat.insert(5);
    for(int i = 0; i < 17; i++)
    {
        aat.insert(a[i]);
    }
    cout<<"find 2 is"<<(aat.find(2)?" true":" false")<<endl;

    aat.remove(2);
    cout<<"find 2 is"<<(aat.find(2)?" true":" false")<<endl;
    


    return 0;
}