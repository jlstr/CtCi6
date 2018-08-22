#include <iostream>
#include "../Stack2/Stack.cpp"

template<class T>
class MyQueue {

public:
  MyQueue();
  void add(const T&);
  void remove();
  const T peek();

private:
  Stack<T> left;
  Stack<T> right;
};

int main() {
  MyQueue<int> queue;

  for (int i = 1; i < 5; ++i) {
    queue.add(i);
  }

  queue.remove();
  std::cout << queue.peek() << std::endl;

  return 0;
}

template<class T>
MyQueue<T>::MyQueue() {
}

template<class T>
void MyQueue<T>::add(const T &item) {
  Stack<T> &currentStack = left;

  if (this->left.isEmpty() && this->right.isEmpty()) {
    currentStack = left;
  } else {
    currentStack = (this->left.isEmpty()) ? this->right : this->left;
  }

  currentStack.push(item);
}

template<class T>
void MyQueue<T>::remove() {
  Stack<T> &currentStack = left;
  Stack<T> &emptyStack = right;

  currentStack = (this->left.isEmpty()) ? this->right : this->left;
  emptyStack = (!this->left.isEmpty()) ? this->right : this->left;

  while (!currentStack.isEmpty()) {
    emptyStack.push(currentStack.peek());
    currentStack.pop();
  }

  emptyStack.pop();

  while (!emptyStack.isEmpty()) {
    currentStack.push(emptyStack.peek());
    emptyStack.pop();
  }
}

template<class T>
const T MyQueue<T>::peek() {
  Stack<T> &currentStack = left;
  Stack<T> &emptyStack = right;

  currentStack = (this->left.isEmpty()) ? this->right : this->left;
  emptyStack = (!this->left.isEmpty()) ? this->right : this->left;

  while (!currentStack.isEmpty()) {
    emptyStack.push(currentStack.peek());
    currentStack.pop();
  }

  const T item = emptyStack.peek();

  while (!emptyStack.isEmpty()) {
    currentStack.push(emptyStack.peek());
    emptyStack.pop();
  }

  return item;
}
