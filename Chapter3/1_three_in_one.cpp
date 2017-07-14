#include <iostream>
#include <vector>
#define NUM_STACKS 3
using namespace std;

template<class Data>
class ThreeStacks {

  public:
  ThreeStacks(int stackSize=1000) {
    array = new Data[3*stackSize];
    
    for (int i = 0; i < NUM_STACKS; ++i) {
      stackIndex[i] = stackSize * i;
      stackCapacity[i] = 0;
    }
  }

  private:
  Data *array;
  int stackIndex[NUM_STACKS];
  int stackCapacity[NUM_STACKS];


  public:
  void push(const int &stackNum, const Data &data) {
    if (stackNum < 1 || stackNum > 3)
      return;

    if (stackCapacity[stackNum-1] == 999)
      return;

    array[stackIndex[stackNum-1]] = data;
    stackIndex[stackNum-1]++;
    stackCapacity[stackNum-1]++;
  }

  Data peek(const int &stackNum) {
    return array[stackIndex[stackNum-1] - 1];
  }

  void pop(const int &stackNum) {
    array[stackIndex[stackNum-1]] = 0;
    stackIndex[stackNum-1]--;
  }

};

int main() {
  ThreeStacks<int> stacks;

  stacks.push(2, 666);
  stacks.push(2, 777);
  stacks.pop(2);
  
  cout << stacks.peek(2) << endl;

  return 0;
}
