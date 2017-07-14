#include "Stack/Stack.h"
#include "Stack/Stack.cpp"
#include <iostream>
using namespace std;

int main() {

  Stack<int> stack;

  stack.push(3);
  stack.push(666);
  stack.push(9);
  stack.push(4);
  stack.push(1);
  stack.push(7);
  stack.push(-1);
  stack.push(999);

  cout << stack.min() << endl;

  return 0;
}
