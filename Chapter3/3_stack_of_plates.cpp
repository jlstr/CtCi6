#include "Stack/Stack.h"
#include "Stack/Stack.cpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<class Data>
class SetOfStacks {

  private:
  double capacityPerStack;
  int stackIndex;
  int elementCount;
  vector< Stack<Data> > stacks;

  public:
  SetOfStacks(int capacityPerStack=5) {
    this->capacityPerStack = double(capacityPerStack);
    this->stackIndex = 0;
    this->elementCount = 0;
    stacks.push_back(Stack<Data>());
  }

  void push(const Data &data) {
    int index = ceil(double(++elementCount / capacityPerStack)) - 1;

    if (index > stackIndex) {
      stacks.push_back(Stack<Data>());
      stackIndex = index;
    }

    stacks[stackIndex].push(data);
  }

  void pop() {
    int index = ceil(double(elementCount / capacityPerStack)) - 1;
    stacks[index].pop();

    int newIndex = ceil(double(--elementCount / capacityPerStack)) - 1;
    if (newIndex < stackIndex) {
      --stackIndex;
      stacks.pop_back();
    }
  }

  Data peek() {
    return stacks[stackIndex].peek();
  }

};

int main() {
  SetOfStacks<int> setOfStacks;

  for (int i = 1; i <= 7; ++i)
    setOfStacks.push(i);

  cout << "Peek -> " << setOfStacks.peek() << endl;

  setOfStacks.pop();
  setOfStacks.pop();

  cout << "Peek -> " << setOfStacks.peek() << endl;

  return 0;
}
