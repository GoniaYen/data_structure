#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//顺序查找表
template <class Type>
int seqSearch(vector<Type> &data, const Type &x)
{
    int pos = -1;
    int i;
    for (i = 0; i < data.size() + 1; ++i)
    {
        if (x == data[i])
        {
            pos = i;
        }
    }

    return pos;
}
//二分查找
template <class Type>
int binSearch(vector<Type> &data, const Type &x)
{
    int low = 0, hight = data.size(), mid;
    while (low <= hight)
    {
        mid = (low + hight) / 2;

        if (x == data[low])
        {
            return low;
        }
        if (x == data[mid])
        {
            return mid;
        }

        if (x == data[hight])
        {
            return hight;
        }

        if (x < data[mid])
        {
            hight = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
void test_stltable()
{
    int a[] = {1, 23, 56, 58, 65, 89, 90, 97, 101};
    vector<int> v;
    vector<int>::iterator itr;
    for (int i = 0; i < 9; i++)
    {
        v.push_back(a[i]);
    }
    if (binary_search(v.begin(), v.end(), 90))
    {
        cout << "90存在" << endl;
    }
    else
    {
        cout << "90不存在" << endl;
    }
    itr = find(v.begin(), v.end(), 90);
    //cout << *itr << endl;
}

int main(int argc, char **argv)
{
    int x[] = {1, 23, 56, 58, 65, 89, 90, 97, 101};
    vector<int> v;
    for (int i = 0; i < 9; i++)
    {
        v.push_back(x[i]);
    }
    cout << "＋＋＋＋＋顺序查找＋＋＋＋＋" << endl;

    int p = seqSearch(v, 9000);
    cout << p << endl;
    cout << "＋＋＋＋＋二分查找＋＋＋＋＋" << endl;
    p = binSearch(v, 90);

    cout << p << endl;
    cout << "＋＋＋＋＋STL静态查找＋＋＋＋＋" << endl;
    test_stltable();

    return 0;
}