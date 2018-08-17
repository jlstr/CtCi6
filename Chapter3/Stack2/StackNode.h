#ifndef STACKNODE_H
#define STACKNODE_H

template<class T>
class Stack; // forward declaration

template<class T>
class StackNode {
public:
  // Stack class has access to private parts of StackNode using friend
  friend class Stack<T>;

  StackNode();
  StackNode(T data, StackNode *next);
private:
  T data;
  StackNode *next;
  StackNode *min;
};

#endif
