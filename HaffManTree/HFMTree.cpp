#ifndef __HFMTREE_H__
#define __HFMTREE_H__
#include <string>
using namespace std;

template <class Type>
class HFMTree
{
private:
  struct node
  {
    Type data;
    int weight;
    int parent, left, right;
  };
  node *elem;
  int length;

public:
  struct HFMCode
  {
    Type data;
    //char code[];
    string code;
  };
  HFMTree(const Type * v, const int * w, int size);
  void get_code(HFMCode result[]);
  ~HFMTree();
};


template <class Type>
HFMTree<Type>::HFMTree(const Type *v, const int *w, int size)
{
    const int MAX_INT = 32767;
    int min1, min2; //最小树。次最小树的权值
    int x, y;       //最小树。次小树的下标

    length = 2 * size;
    elem = new node[length];

    for (int i = size; i < length; ++i)
    {
        elem[i].weight = w[i - size];
        elem[i].data = v[i - size];
        elem[i].parent = elem[i].left = elem[i].right = 0;
    }

    //归并森林中的树
    for (int i = size - 1; i > 0; i--)
    {
        min1 = min2 = MAX_INT;
        x = y = 0;
        for (int j = i + 1; j < length; j++)
        {
            if (elem[j].parent == 0)
            {
                if (elem[j].weight < min1)
                {
                    min2 = min1;
                    min1 = elem[j].weight;
                    x=y;
                    y = j;
                }
                else if (elem[j].weight < min2)
                {
                    min2 = elem[j].weight;
                    x = j;
                }
            }
            elem[i].weight = min1 + min2;
            elem[i].left = x;
            elem[i].right = y;
            elem[i].parent = 0;
        }
        elem[x].parent = i;
        elem[y].parent = i;
    }
}
template <class Type>
void HFMTree<Type>::get_code(HFMCode result[])
{

    int size = length / 2;
    //cout<<size<<endl;
    int p, s; //s是追溯过程中正在处理节点的下表，p是ｓ的父节点下标
    for (int i = size; i < length; i++)
    {
        result[i - size].data = elem[i].data;
        result[i - size].code = " ";
        p = elem[i].parent;

        s = i;

        do
        { //向根追溯

            if (elem[p].left == s)
            {

                result[i - size].code = '0' + result[i - size].code;
            }
            else
            {
                result[i - size].code = '1' + result[i - size].code;
            }
            s = p;
            p = elem[p].parent;
        } while (p);
    }
}

template <class Type>
HFMTree<Type>::~HFMTree()
{
    delete[] elem;
}
#endif