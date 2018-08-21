#include <iostream>
#include <vector>
#include "../Stack2/Stack.cpp"

template<class T>
class SetOfStacks {
public:
  SetOfStacks(const int &stackCapacity=10);
  void push(const T&);
  void pop();
  const T peek();

private:
  std::vector< Stack<T> > stacks;
  int capacityPerStack;
  int stackIndex;

  Stack<T>& currentStack();
  Stack<T>& addStack();
  Stack<T>& removeStack();
};

int main() {
  SetOfStacks<int> stack(3);

  for (int i = 0; i < 10; ++i)
    stack.push(i);

  std::cout << "At the Top: " << stack.peek() << std::endl;

  return 0;
}

template<class T>
SetOfStacks<T>::SetOfStacks(const int &capacity) {
  this->capacityPerStack = capacity;
  this->stacks.push_back(Stack<T>());
  this->stackIndex = 0;
}

template<class T>
void SetOfStacks<T>::push(const T &item) {
  if (currentStack().size() < this->capacityPerStack) {
    currentStack().push(item);
  } else {
    addStack().push(item);
  }
}

template<class T>
void SetOfStacks<T>::pop() {
  currentStack().pop();

  if (currentStack().isEmpty()) {
    removeStack();
  }
}

template<class T>
const T SetOfStacks<T>::peek() {
  return currentStack().peek();
}

template<class T>
Stack<T>& SetOfStacks<T>::currentStack() {
  return this->stacks[stackIndex];
}

template<class T>
Stack<T>& SetOfStacks<T>::addStack() {
  this->stacks.push_back(Stack<T>());
  return this->stacks[++this->stackIndex];
}

template<class T>
Stack<T>& SetOfStacks<T>::removeStack() {
  this->stacks.pop_back();
  return this->stacks[--this->stackIndex];
}
