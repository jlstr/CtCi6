#include <iostream>

class ThreeInOne {
public:
  ThreeInOne(const int &capacity=1000);
  void push(const int&, const int &stack=0);
  void pop(const int &stack=0);
  int peek(const int &stack=0);

private:
  int *stacks;
  int *indexes;
};

int main() {
  ThreeInOne stacks;

  stacks.push(1);
  stacks.push(2);
  stacks.push(666);
  stacks.pop();

  std::cout << stacks.peek() << std::endl;

  stacks.push(3, 1);
  stacks.push(4, 1);
  stacks.push(777, 1);

  std::cout << stacks.peek(1) << std::endl;

  return 0;
}

ThreeInOne::ThreeInOne(const int &capacity) {
  this->stacks = new int[3 * capacity];
  this->indexes = new int[3];
  indexes[0] = 0;
  indexes[1] = 0;
  indexes[2] = 0;
}

void ThreeInOne::push(const int &item, const int &stack) {
  if (stack < 0 || stack > 2)
    return;

  int index = (indexes[stack]++) + (stack*1000);
  this->stacks[index] = item;
}

void ThreeInOne::pop(const int &stack) {
  int index = (--indexes[stack]) + (stack*1000);
  this->stacks[index] = 0;
}

int ThreeInOne::peek(const int &stack) {
  int index = (indexes[stack]-1) + (stack*1000);
  return this->stacks[index];
}
