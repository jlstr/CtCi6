#include "../Stack2/Stack.cpp"
#include <iostream>

int main() {
  Stack<int> stack;

  stack.push(2);
  stack.push(333);
  stack.push(666);
  // stack.pop();

  stack.print();

  try {
    int min = stack.min();
    std::cout << "MIN: " << min << std::endl;
  } catch(EmptyException &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
