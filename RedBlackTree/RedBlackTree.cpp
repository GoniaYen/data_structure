#include <iostream>
#include "listStack.cpp"
using namespace std;
template <class Type>
class RedBlackTree
{

private:
    struct RedBlackNode
    {
        Type data;
        RedBlackNode *left;
        RedBlackNode *right;
        int colour; // 0:红色，1:黑色
        RedBlackNode(const Type &elem, RedBlackNode *lt, RedBlackNode *rt, int h = 0) : data(elem), left(lt), right(rt), colour(h) {}
    };

    RedBlackNode *root;

public:
    RedBlackTree(RedBlackNode *t = NULL);
    ~RedBlackTree();
    bool find(const Type &x) const;
    void insert(const Type &x);
    void remove(const Type &x);

private:
    void makeEmpty(RedBlackNode *&t);
    void LL(RedBlackNode *&t);
    void LR(RedBlackNode *&t);
    void RL(RedBlackNode *&t);
    void RR(RedBlackNode *&t);
    void reLink(RedBlackNode *oldp, RedBlackNode *newp, listStack<RedBlackNode *> &path);
    void insertReBalance(RedBlackNode *t, listStack<RedBlackNode *> &path);
    void removetReBalance(RedBlackNode *t, listStack<RedBlackNode *> &path);
};
template <class Type>
RedBlackTree<Type>::RedBlackTree(RedBlackNode *t) 
{
     root = t;
}
template <class Type>
RedBlackTree<Type>::~RedBlackTree()
{
    makeEmpty(root);
}
template <class Type>
bool RedBlackTree<Type>::find(const Type &x) const
{
    RedBlackNode *t = root;
    while (t != NULL && t->data != x)
    {
        if (t->data > x)
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
void RedBlackTree<Type>::insert(const Type &x)
{
    listStack<RedBlackNode *> path;
    RedBlackNode *t, *parent;
    if (root == NULL)
    {
        root = new RedBlackNode(x, NULL, NULL,1);
        return;
    }
    t = root;

    //寻找插入位置，并将路径放入栈中

    while (t != NULL && t->data != x)
    {
        path.push(t);
        if (t->data < x)
        {
            t = t->right;
        }
        else
        {
            t = t->left;
        }
    }

    if (t != NULL)
        return; //找到重复节点，放弃插入

    //执行插入过程
    t = new RedBlackNode(x, NULL, NULL);
    parent = path.pop();
    if (x < parent->data)
    {
        parent->left = t;
    }
    else
    {
        parent->right = t;
    }
    if (parent->colour == 1)
        return; //如果父节点是黑色，则不需要调整

    //将父节点压入栈中　从插入节点开始调整

    path.push(parent);
    insertReBalance(t, path);
}
template <class Type>
void RedBlackTree<Type>::remove(const Type &x)
{
    listStack<RedBlackNode *> path; //保存根节点到被删除节点的路径
    RedBlackNode *t = root, *old, *parent = NULL;
    //寻找节点，并保存路径
    while (t != NULL && t->data != x)
    {
        path.push(t);
        if (t->data > x)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    //没有找到要删除的节点，放弃删除
    if (t == NULL)
    {
        return;
    }
    //找代替节点并代替
    if (t->left != NULL && t->right != NULL)
    {
        path.push(t);
        old = t;
        t = t->right;
        while (t->left != NULL)
        {
            path.push(t);
            t = t->left;
        }
        old->data = t->data;
    }
    //执行删除.删除根节点
    if (t == root)
    {
        root = (t->left ? t->left : t->right);
        if (root != NULL)
        {
            root->colour = 1;
        }
        return;
    }
    //删除叶节点或者只有一个子节点的节点

    parent = path.pop();
    old = t;
    t = (t->left ? t->left : t->right);
    if (parent->left == old)
    {
        parent->left = t;
    }
    else
    {
        parent->right = t;
    }
    //删除红节点

    if (old->colour == 0)
    {
        delete old;
        return;
    }
    delete old; //有一个子节点｀????????????????????????

    if (t != NULL)
    {
        t->colour = 1;
        return;
    }

    path.push(parent);
    removetReBalance(t, path);
}
template <class Type>
void RedBlackTree<Type>::makeEmpty(RedBlackNode *&t)
{
    if (t != NULL)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}
template <class Type>
void RedBlackTree<Type>::LL(RedBlackNode *&t)
{
    RedBlackNode* t1 = t->left;
    t->left = t1->right;
    t1->right = t;
    t = t1;
}
template <class Type>
void RedBlackTree<Type>::LR(RedBlackNode *&t)
{
    RR(t->left);
    LL(t);
}
template <class Type>
void RedBlackTree<Type>::RL(RedBlackNode *&t)
{
    LL(t->right);
    RR(t);
}
template <class Type>
void RedBlackTree<Type>::RR(RedBlackNode *&t)
{
    RedBlackNode *t1 = t->right;
    t->right = t1->left;
    t1->left = t;
    t = t1;
}
template <class Type>
void RedBlackTree<Type>::reLink(RedBlackNode *oldp, RedBlackNode *newp, listStack<RedBlackNode *> &path)
{
    if (path.isEmpty())
    {
        root = newp;
    }
    else
    {
        RedBlackNode *grandParent = path.pop();
        if (grandParent->left == oldp)
        {
            grandParent->left = newp;
        }
        else
        {
            grandParent->right = newp;
        }
        path.push(grandParent);
    }
}
template <class Type>
void RedBlackTree<Type>::insertReBalance(RedBlackNode *t, listStack<RedBlackNode *> &path)
{
    RedBlackNode *parent, *grandParent, *uncle, *rootOfSubTree;
    parent = path.pop();
    //父节点时红色时　需要调整
    while (parent->colour == 0)
    {
        //父节点时根
        if (parent == root)
        {
            parent->colour = 1;
            return;
        }
        grandParent = rootOfSubTree = path.pop();
        //找出叔叔节点
        if (grandParent->data > parent->data)
        {
            uncle = grandParent->right;
        }
        else
        {
            uncle = grandParent->left;
        }
        //叔叔节点是空节点或者是黑节点
        if (uncle == NULL || uncle->colour == 1)
        {
            if (grandParent->left == parent)
            {
                if (t == parent->left) //LLb
                {
                    parent->colour = 1;
                    grandParent->colour = 0;
                    LL(grandParent);
                }
                else //LRb
                {
                    grandParent->colour = 0;
                    t->colour = 1;
                    LR(grandParent);
                }
            }
            if (grandParent->right == parent)
            {
                if (t == parent->right)
                { //RRb
                    parent->colour = 1;
                    grandParent->colour = 0;
                    RR(grandParent);
                }
                else //RLb
                {
                    grandParent->colour = 0;
                    t->colour = 1;
                    RL(grandParent);
                }
            }
            reLink(rootOfSubTree, grandParent, path);
            return;
        }
        else //叔叔节点是红节点
        {
            grandParent->colour = 0;
            parent->colour = 1;
            uncle->colour = 1;
            if (root == grandParent)
            {
                root->colour = 1;
                return;
            }
            t = grandParent;
            parent = path.pop();
        }
    }
}
template <class Type>
void RedBlackTree<Type>::removetReBalance(RedBlackNode *t, listStack<RedBlackNode *> &path)
{
    RedBlackNode *parent, *sibing, *rootOfSubTree;
    parent = rootOfSubTree = path.pop();
    while (parent != NULL) //处理Ｌ０，Ｒ０，或情况二
    {
        if (parent->left == t)
        {
            sibing = parent->right;
        }
        else
        {
            sibing = parent->left;
        }
        if (sibing->colour == 0) //情况二
        {
            sibing->colour = 1;
            parent->colour = 0;
            if (parent->left == t)
            {
                RR(parent);
            }
            else
            {
                LL(parent);
            }
            reLink(rootOfSubTree, parent, path);
            path.push(parent);
            parent = rootOfSubTree;
        }
        else //兄弟是黑节点
        {
            if ((sibing->left == NULL || sibing->left->colour == 1) && (sibing->right == NULL || sibing->right->colour == 1)) // L0 OR R0
            {
                sibing->colour = 0;
                if (parent->colour == 0)
                {
                    parent->colour = 1;
                    return;
                }
                else
                {
                    t = parent;
                    if (t == root)
                    {
                        return;
                    }
                    else
                    {
                        parent = rootOfSubTree = path.pop();
                    }
                }
            }
            else
            {
                break;
            }
        }
    }

    if (parent->left == t)
    { //兄弟是右儿子
        if (sibing->left != NULL && sibing->left->colour == 0)
        {
            //R1L OR R2
            sibing->left->colour = parent->colour;
            parent->colour = 1;
            RL(parent);
            reLink(rootOfSubTree, parent, path);
        }
        else
        {
            //R1R
            sibing ->colour = parent->colour;
            sibing->right->colour =1;
            parent->colour =1;
            RR(parent);
            reLink(rootOfSubTree,parent,path);
        }
    }
    else//兄弟是左儿子
    {
        if (sibing->right != NULL && sibing->right->colour == 0)
        {
            //L1R OR L2
            sibing->right->colour = parent->colour;
            parent->colour = 1;
            LR(parent);
            reLink(rootOfSubTree, parent, path);
        }
        else
        {
            //L1L
            sibing ->colour = parent->colour;
            sibing->left->colour =1;
            parent->colour =1;
            LL(parent);
            reLink(rootOfSubTree,parent,path);
        }
        
    }
    
}
