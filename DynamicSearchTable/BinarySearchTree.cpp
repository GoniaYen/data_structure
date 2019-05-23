#include <iostream>



using namespace std;

template <class Type>
class BinarySearchTree
{
  private:
    struct BinaryNode
    {
        Type data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const Type &_data, BinaryNode *_left, BinaryNode *_right) : data(_data), left(_left), right(_right) {}
    };

    BinaryNode *root;

    void insert(const Type &x, BinaryNode* &t);
    void remove(const Type &x, BinaryNode* &t);
    bool find(const Type &x, BinaryNode *t) const;
    void makeEmpty(BinaryNode *&t);

  public:
    BinarySearchTree(BinaryNode *t=NULL );
    ~BinarySearchTree();
    void insert(const Type &x);
    void remove(const Type &x);
    bool find(const Type &x) const;
};
template <class Type>
BinarySearchTree<Type>::BinarySearchTree(BinaryNode *t) 
{
    root = t;
}
template <class Type>
BinarySearchTree<Type>::~BinarySearchTree()
{
    makeEmpty(root);
}
template <class Type>
void BinarySearchTree<Type>::insert(const Type &x)
{
    insert(x, root);
    
}
template <class Type>
void BinarySearchTree<Type>::remove(const Type &x)
{
    remove(x, root);
}
template <class Type>
bool BinarySearchTree<Type>::find(const Type &x) const
{
    return find(x, root);
}

template <class Type>
void BinarySearchTree<Type>::insert(const Type &x, BinaryNode *&t)
{
    //cout<<t->data;
    //cout<<root->data;
    if (t == NULL)
    {
        t = new BinaryNode(x, NULL, NULL);
    }
    else if (x < t->data)
    {
        insert(x, t->left);
    }
    else if (x > t->data)
    {
        insert(x, t->right);
    }
}
template <class Type>
void BinarySearchTree<Type>::remove(const Type &x, BinaryNode *&t)
{

    if(t==NULL) return ;
    if(x<t->data) {
        remove(x,t->left);
    }else if (x>t->data)
    {
        remove(x,t->right);
    }else if (t->left!=NULL&&t->right!=NULL)//被删除节点有两个子节点 右子树最小的值代替被删除的节点
    {
        BinaryNode *tmp = t->right;
        while(tmp->left!=NULL) tmp = tmp->left; //右子树最小的值位于左节点
        t->data = tmp->data;//把右子树最小的值放入被删除节点
        remove(t->data,t->right);
    }
    else//被删除节点是叶子节点或只有一个子节点
    {
        BinaryNode *oldNode = t;
        t=(t->left!=NULL)?t->left:t->right;
        delete oldNode;
    }
    
    
    
}
template <class Type>
bool BinarySearchTree<Type>::find(const Type &x, BinaryNode *t) const
{
    if (t == NULL)
    {
        return false;
    }
    else if (x == t->data)
    {
        return true;
    }

    else if (x < t->data)
    {
        return find(x, t->left);
    }
    else if (x > t->data)
    {
        return find(x, t->right);
    }

    return false;
}
template <class Type>
void BinarySearchTree<Type>::makeEmpty(BinaryNode *&t)
{
    if(t==NULL){
        return;
    }else
    {
        BinaryNode *lt = t->left;
        BinaryNode *rt = t->right;
        delete t;

        makeEmpty(lt);
        makeEmpty(rt);


    }

  
    
}
