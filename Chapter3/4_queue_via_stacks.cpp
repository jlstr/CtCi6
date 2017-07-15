#include "Stack/Stack.h"
#include "Stack/Stack.cpp"
#include <iostream>
using namespace std;

template<class Data>
class MyQueue {

  private:
  Stack<Data> stack1;
  Stack<Data> stack2;

  public:
  
  void add(const Data &data) {
    stack1.push(data);
  }

  void remove() {
    while (!stack1.empty()) {
      stack2.push(stack1.peek());
      stack1.pop();
    }

    stack2.pop();

    while (!stack2.empty()) {
      stack1.push(stack2.peek());
      stack2.pop();
    }
  }

  Data peek() {
    while (!stack1.empty()) {
      stack2.push(stack1.peek());
      stack1.pop();
    }

    Data data = stack2.peek();

    while (!stack2.empty()) {
      stack1.push(stack2.peek());
      stack2.pop();
    }

    return data;
  }

};

int main() {

  MyQueue<int> queue;

  queue.add(1);
  queue.add(2);
  queue.add(3);

  cout << queue.peek() << endl;
  queue.remove();
  cout << queue.peek() << endl;

  return 0;
}
