
#include <iostream>

using namespace std;
template <class Type>
class AvlTree
{
  private:
    struct AvlNode
    {
        Type data;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Type &x, AvlNode *lt = NULL, AvlNode *rt = NULL, int h = 0) : data(x), left(lt), right(rt), height(h) {}
    };
    AvlNode *root = NULL;
    void insert(const Type &x, AvlNode *&t);
    bool remove(const Type &x, AvlNode *&t);
    bool find(const Type &x, AvlNode *t) const;
    void makeEmpty(AvlNode *&t);
    void LL(AvlNode *&t);
    void LR(AvlNode *&t);
    void RL(AvlNode *&t);
    void RR(AvlNode *&t);
    int max(int a, int b);
    int height(AvlNode *t);

  public:
    AvlTree(AvlNode *t = NULL);
    ~AvlTree();
    void insert(const Type &x);
    void remove(const Type &x);
    bool find(const Type &x) const;
};
template <class Type>
AvlTree<Type>::AvlTree(AvlNode *t)
{
    root = t;
}
template <class Type>
AvlTree<Type>::~AvlTree()
{
    makeEmpty(root);
}
template <class Type>
void AvlTree<Type>::insert(const Type &x)
{
    insert(x, root);
}
template <class Type>
void AvlTree<Type>::remove(const Type &x)
{
    remove(x, root);
}
template <class Type>
bool AvlTree<Type>::find(const Type &x) const
{
    return find(x, root);
}

//private
template <class Type>
void AvlTree<Type>::insert(const Type &x, AvlNode *&t)
{
    if (t == NULL)
    {
        t = new AvlNode(x, NULL, NULL, 0);
    }
    else if (x < t->data)
    {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
            if (x < t->left->data)
            {
                LL(t);
            }
            else
            {
                LR(t);
            }
        }
    }
    else if (x > t->data)
    {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
            if (x > t->right->data)
            {
                RR(t);
            }
            else
            {
                RL(t);
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}
template <class Type>
bool AvlTree<Type>::remove(const Type &x, AvlNode *&t)
{
    bool stop = false;
    int subTree;
    if (t == NULL)
    {
        return true;
    }
    else if (x < t->data)
    {
        stop = remove(x, t->left);
        subTree = 1;
    }
    else if (x > t->data)
    {
        stop = remove(x, t->right);
        subTree = 2;
    }
    else if (t->left != NULL && t->right != NULL)
    {
        AvlNode *tmp = t->right;
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        t->data = tmp->data;
        stop = remove(t->data, t->right);
        subTree = 2;
    }
    else
    {
        AvlNode *tmp = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete tmp;
        return false;
    }
    if (stop)
        return true;
    int bf;
    switch (subTree)
    {
    case 1:
        bf = height(t->left) - height(t->right) + 1;
        if (bf == 0)
            return true;
        if (bf == 1)
            return true;
        if (bf == -1)
        {
            int bfr = height(t->right->left) - height(t->right->left);
            switch (bfr)
            {
            case 0:
                RR(t);
                return true;
            case -1:
                RR(t);
                return false;
            default:
                RL(t);
                return false;
            }
        }
        break;
    case 2:
        bf = height(t->left) - height(t->right) - 1;
        if (bf == 0)
            return true;
        if (bf == -1)
            return true;
        if (bf == 1)
        {
            int bfl = height(t->left->left) - height(t->left->right);
            switch (bfl)
            {
            case 0:
                LL(t);
                return true;
            case -1:
                LL(t);
                return false;
            default:
                LR(t);
                return false;
            }
        }
        break;
    }
}
template <class Type>
bool AvlTree<Type>::find(const Type &x, AvlNode *t) const
{

    while (t != NULL && t->data != x)
    {
        if (x < t->data)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    if (t == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
template <class Type>
void AvlTree<Type>::makeEmpty(AvlNode *&t)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        AvlNode *tmpl = t->left;
        AvlNode *tmpr = t->right;
        delete t;
        makeEmpty(tmpl);
        makeEmpty(tmpr);
    }
    t=NULL;
}
template <class Type>
void AvlTree<Type>::LL(AvlNode *&t)
{
    AvlNode *t1 = t->left;
    t->left = t1->right;
    t1->right = t;
    t->height = max(height(t->left), height(t->left)) + 1;
    t1->height = max(height(t->left), height(t)) + 1;
    t = t1;
}
template <class Type>
void AvlTree<Type>::LR(AvlNode *&t)
{
    RR(t->left);
    LL(t);
}
template <class Type>
void AvlTree<Type>::RL(AvlNode *&t)
{
    LL(t->right);
    RR(t);
}
template <class Type>
void AvlTree<Type>::RR(AvlNode *&t)
{
    AvlNode *t1 = t->right;
    t->right = t1->left;
    t1->left = t;
    t->height = max(height(t->left), height(t->left)) + 1;
    t1->height = max(height(t->left), height(t)) + 1;
    t = t1;
}
template <class Type>
int AvlTree<Type>::max(int a, int b)
{
    return (a > b) ? a : b;
}
template <class Type>
int AvlTree<Type>::height(AvlNode *t)
{
    return (t == NULL) ? -1 : t->height;
}