#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
template <class Type>
class Tree
{
private:
public:
  virtual ~Tree(){};
  virtual void createTree(Type flag) = 0;
  virtual void clear() = 0;
  virtual bool isEmpty() const = 0;
  virtual Type getRoot() const = 0;
  //virtual Type getParent()const=0; ////标准二叉树的实现,不实现此函数
  virtual Type getLchild() const = 0;
  virtual Type getRchild() const = 0;
  virtual void delLeft() = 0;
  virtual void delRight() = 0;
  virtual void preOrder() const = 0;  //前序遍历
  virtual void midOrder() const = 0;  //中序遍历
  virtual void postOrder() const = 0; //后序遍历
};

#endif
