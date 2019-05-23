
#include "binaryTree.cpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // binaryTree<int> p(1);
    // binaryTree<int> p1(2);
    

    // binaryTree<int> p4;
    // p4.makeTree(0, p, p1);
    // p4.preOrder();
    // p4.midOrder();
    // p4.postOrder();
    // cout <<"p4 size:"<<p4.size()<<" p4 height "<<p4.height()<<endl;
  
    // binaryTree<int> p5;

    // p5.makeTree(200,p1,p4);
    // p5.preOrder();
    // p5.midOrder();
    // p5.postOrder();



    // cout <<"p5 size:"<<p5.size()<<" p5 height:"<<p5.height()<<endl;

    binaryTree< char > tree;
    tree.createTree('@');
    cout<<"高度为："<<tree.height()<<endl;
    cout<<"规模为："<<tree.size()<<endl;
    cout<<"+++++++++++++递归遍历++++++++++++++"<<endl;
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    cout<<"++++++++++++非递归遍历++++++++++++++"<<endl;
    tree.preOrder_();
    tree.midOrder_();
    tree.postOrder_();

   
    
    return 0;
}