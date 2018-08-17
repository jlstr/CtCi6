#ifndef QUEUENODE_H
#define QUEUENODE_H

template<class T>
class Queue;

template<class T>
class QueueNode {
public:
  friend class Queue<T>;

  QueueNode(T, QueueNode*);

private:
  T item;
  QueueNode *next;
};

#endif
