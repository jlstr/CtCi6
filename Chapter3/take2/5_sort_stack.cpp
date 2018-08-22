#include <iostream>
#include "../Stack2/Stack.cpp"

void sortStack(Stack<int>&);

int main() {
  
  Stack<int> stack;

  stack.push(4);
  stack.push(1);
  stack.push(3);
  stack.push(7);
  stack.push(2);

  stack.print();
  std::cout << "==============================" << std::endl;
  sortStack(stack);
  stack.print();

  return 0;
}

void sortStack(Stack<int> &stack) {
  Stack<int> auxStack;

  while (!stack.isEmpty()) {
    int pushes = 0;

    int item = stack.peek();
    stack.pop();

    if (auxStack.isEmpty()) {
      auxStack.push(item);
  
    } else {
    
      while (!auxStack.isEmpty() && auxStack.peek() > item ) {
        stack.push(auxStack.peek());
        auxStack.pop();
        pushes++;
      }

      auxStack.push(item);

      while (pushes > 0) {
        auxStack.push(stack.peek());
        auxStack.pop();
        pushes--;
      }
    }
  }

  while (!auxStack.isEmpty()) {
    stack.push(auxStack.peek());
    auxStack.pop();
  }
}