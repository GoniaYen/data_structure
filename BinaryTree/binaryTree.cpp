#include "binaryTree.h"
#include "queue.h"
#include "linkQueue.cpp"

#include "linkStack.cpp"
#include <iostream>

using namespace std;

template <class Type>
class binaryTree : public Tree<Type>
{
  private:
    struct Node //二叉树节点类
    {
        Node *left, *right; //左右字节点的地址
        Type data;          //节点数据
        Node() : left(NULL), right(NULL)
        {
        }
        Node(Type d, Node *L = NULL, Node *R = NULL) : data(d), left(L), right(R)
        {
        }
    };
    Node *root;
    struct StNode
    {
        Node *node;
        int TimePop;
        StNode(Node *N = NULL) : node(N), TimePop(0) {}
    };

    void clear(Node *t);
    void preOrder(Node *t) const;  //前序遍历
    void midOrder(Node *t) const;  //中序遍历
    void postOrder(Node *t) const; //后序遍历
    int height(Node *t) const;
    int size(Node *t) const;

  public:
    //遍历的非递归实现
    void preOrder_() const;
    void midOrder_() const;
    void postOrder_() const;
    binaryTree() : root(NULL){};
    binaryTree(const Type &value) { root = new Node(value); }
    binaryTree(Node *p) { root = p; }
    ~binaryTree() { clear(); };
    bool isEmpty() const { return root == NULL; }
    Type getRoot() const { return root->data; }
    // // Type getParent()const; ////标准二叉树的实现,不实现此函数
    Type getLchild() const { return root->left->data; }
    Type getRchild() const { return root->right->data; }
    void delLeft()
    {
        binaryTree tmp = root->left;
        root->left = NULL;
        tmp.clear();
    }
    void delRight()
    {
        binaryTree tmp = root->right;
        root->right = NULL;
        tmp.clear();
    }
    int size() const { return size(root); }
    int height() const { return height(root); }
    void clear()
    {
        if (root != NULL)
            clear(root);
        root = NULL;
    }
    void preOrder() const //前序遍历
    {
        if (root != NULL)
        {
            cout << "\n前序遍历:";
            preOrder(root);
        }
        cout << endl;
    }
    void midOrder() const //中序遍历
    {
        if (root != NULL)
        {
            cout << "\n中序遍历:";
            midOrder(root);
        }
        cout << endl;
    }
    void postOrder() const //后序遍历
    {
        if (root != NULL)
        {
            cout << "\n后序遍历:";
            postOrder(root);
        }
        cout << endl;
    }

    void makeTree(const Type &x, binaryTree &lt, binaryTree &rt)
    {
        root = new Node(x, lt.root, rt.root);
        lt.root = NULL;
        rt.root = NULL;
    }

    void createTree(Type flag);
};

template <class Type>
void binaryTree<Type>::clear(Node *t)
{
    if (t->left != NULL)
        clear(t->left);
    if (t->right != NULL)
        clear(t->right);
    delete t;
}

template <class Type>
void binaryTree<Type>::preOrder(Node *t) const
{
    if (t != NULL)
    {
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}
template <class Type>
void binaryTree<Type>::midOrder(Node *t) const
{
    if (t != NULL)
    {
        midOrder(t->left);
        cout << t->data << " ";
        midOrder(t->right);
    }
}
template <class Type>
void binaryTree<Type>::postOrder(Node *t) const
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
}
template <class Type>
int binaryTree<Type>::height(Node *t) const
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        int lt = height(t->left), rt = height(t->right);
        return 1 + ((lt > rt) ? lt : rt);
    }
}

template <class Type>
int binaryTree<Type>::size(Node *t) const
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        int lt = size(t->left), rt = size(t->right);
        return 1 + lt + rt;
    }
}
template <class Type>
void binaryTree<Type>::createTree(Type flag)
{
    // queue<Node*,list<Node*>>que;
    linkQueue<Node *> que;
    Node *tmp;
    Type x, ldata, rdata;
    cout << "\n输入根节点：";
    cin >> x;
    root = new Node(x);
    que.enQueue(root);

    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << "\n输入" << tmp->data << "的两个儿子(" << flag << "表示空节点):";
        cin >> ldata >> rdata;
        if (ldata != flag)
        {
            que.enQueue(tmp->left = new Node(ldata));
        }
        if (rdata != flag)
        {
            que.enQueue(tmp->right = new Node(rdata));
        }
    }
    cout << "create completed!" << endl;
}

template <class Type>
void binaryTree<Type>::preOrder_() const
{
    linkStack<Node *> s;
    Node *current = nullptr;

    cout << "\n前序遍历:";
    s.push(root);
    while (!s.isEmpty())
    {
        current = s.pop();
        cout << current->data << " ";
        if (current->right != NULL)
            s.push(current->right);
        if (current->left != NULL)
            s.push(current->left);
    }
    cout << endl;
}
template <class Type>
void binaryTree<Type>::midOrder_() const
{
    linkStack<StNode> s;
    StNode current(root);

    cout << "\n中序遍历:";

    s.push(current);

    while (!s.isEmpty())
    {
        current = s.pop();
        //current.TimePop++ ;
        //cout<<current.TimePop;
        if (++current.TimePop == 2)
        {
            // cout<<current.TimePop;
            cout << current.node->data << " ";
            if (current.node->right != NULL)
            {
                s.push(StNode(current.node->right));
            }
        }
        else
        {

            s.push(current);
            if (current.node->left != NULL)
            {
                s.push(StNode(current.node->left));
            }
        }
    }
    cout << endl;
}
template <class Type>
void binaryTree<Type>::postOrder_() const

{
    linkStack<StNode> s;
    StNode current(root);

    cout << "\n后序遍历:";
    s.push(current);
    while (!s.isEmpty())
    {
        current = s.pop();

        if (++current.TimePop == 3)
        {
            cout << current.node->data << " ";
            continue;
        }
        s.push(current);

        if (current.TimePop == 1)
        {
            if (current.node->left != NULL)
                s.push(StNode(current.node->left));
        }
        else
        {
            if (current.node->right != NULL)
                s.push(StNode(current.node->right));
        }
    }
    cout << endl;
}