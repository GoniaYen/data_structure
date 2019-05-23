#include <iostream>

using namespace std;

template <class Type>
class AATree
{
private:
    struct AANode
    {
        Type data;
        AANode *left;
        AANode *right;
        int level;

        AANode(const Type &x, AANode *lt, AANode *rt, int lv = 1) :data(x),left(lt),right(rt),level(lv){}
    };

    AANode *root;

    void insert(const Type &x, AANode *&t);
    void remove(const Type &x, AANode *&t);
    bool find(const Type &x, AANode *t) const;
    void makeEmpty(AANode *&t);
    void LL(AANode *&t);
    void RR(AANode *&t);

public:
    AATree(AANode *t = NULL);
    ~AATree();
    void insert(const Type &x);
    void remove(const Type &x);
    bool find(const Type &x) const;
};
template <class Type>
AATree<Type>::AATree(AANode *t)
{
    root = t;
}
template <class Type>
AATree<Type>::~AATree()
{
    makeEmpty(root);
}

template <class Type>
void AATree<Type>::insert(const Type &x)
{
    insert(x, root);
}
template <class Type>
void AATree<Type>::remove(const Type &x)
{
    remove(x, root);
}
template <class Type>
bool AATree<Type>::find(const Type &x) const
{
    return find(x, root);
}

template <class Type>
void AATree<Type>::insert(const Type &x, AANode *&t)
{
    if (t == NULL)
    {
        t = new AANode(x, NULL, NULL);
    }
    else if (x < t->data)
    {
        insert(x, t->left);
    }
    else if (x > t->data)
    {
        insert(x, t->right);
    }
    else
    {
        return;
    }

    LL(t);
    RR(t);
}
template <class Type>
void AATree<Type>::remove(const Type &x, AANode *&t)
{

    if (t == NULL)
    {
        return;
    }
    else if (x < t->data)
    {
        remove(x, t->left);
    }
    else if (x > t->data)
    {
        remove(x, t->right);
    }
    else if (t->left != NULL && t->right != NULL)
    {
        AANode *tmp = t->right;
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        t->data = tmp->data;
        remove(t->data, t->right);
    }
    else
    {
        AANode *oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
        return;
    }
    if (t->left == NULL || t->right == NULL)
    {
        t->level = 1;
    }
    else
    {
        t->level = min(t->left->level, t->right->level) + 1;
    }
    if (t->right != NULL && t->right->level > t->level)
    {
        t->right->level = t->level;
    }
    LL(t);
    if (t->right != NULL)
    {
        LL(t->right);
    }
    if (t->right != NULL && t->right->right != NULL)
    {
        LL(t->right->right);
    }
    RR(t);
    if (t->right != NULL)
    {
        RR(t->right);
    }
}
template <class Type>
bool AATree<Type>::find(const Type &x, AANode *t) const
{
    if (t == NULL)
    {
        return false;
    }
    else if (x < t->data)
    {
        return find(x, t->left);
    }
    else if (x > t->data)
    {
        return find(x, t->right);
    }
    else
    {
        return true;
    }
}
template <class Type>
void AATree<Type>::makeEmpty(AANode *&t)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        AANode *tmpl = t->left;
        AANode *tmpr = t->right;
        delete t;
        makeEmpty(tmpl);
        makeEmpty(tmpr);
    }
}
template <class Type>
void AATree<Type>::LL(AANode *&t)
{

    if (t->left != NULL && t->left->level == t->level)
    {
        AANode *t1 = t->left;
        t->left = t1->right;
        t1->right = t;
        t = t1;
    }
}
template <class Type>
void AATree<Type>::RR(AANode *&t)
{
    if (t->right != NULL && t->right->right != NULL && t->right->level == t->level)
    {
        AANode *t1 = t->right;
        t->right = t1->left;
        t1->left = t;
        t = t1;
        t->level++;
    }
}
