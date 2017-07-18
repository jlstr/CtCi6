#include "Stack/Stack.h"
#include "Stack/Stack.cpp"
#include <iostream>
using namespace std;

Stack<int> order(Stack<int>&);

int main() {
  Stack<int> stack;

  stack.push(2);
  stack.push(3);
  stack.push(1);
  stack.push(5);
  stack.push(9);
  stack.push(666);
  stack.push(7);
  stack.push(2);

  Stack<int> orderedStack = order(stack);

  while (!orderedStack.empty()) {
    cout << orderedStack.peek() << endl;
    orderedStack.pop();
  }

  return 0;
}

Stack<int> order(Stack<int> &stack) {
  if (stack.empty()) {
    return Stack<int>();
  }

  int data = stack.peek();
  stack.pop();
  Stack<int> orderedStack = order(stack);
  
  if (orderedStack.empty()) {
    orderedStack.push(data);
  } else {

    Stack<int> aux;
    while (!orderedStack.empty() && (data > orderedStack.peek())) {
      int popped = orderedStack.peek();
      orderedStack.pop();
      aux.push(popped);
    }

    orderedStack.push(data);

    while (!aux.empty()) {
      int topValue = aux.peek();
      aux.pop();
      orderedStack.push(topValue);
    }
  }

  return orderedStack;
}
