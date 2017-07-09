#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedList.cpp"
#include <iostream>
using namespace std;

LinkedList<int> sum(LinkedList<int>&, LinkedList<int>&);

int main() {

  LinkedList<int> A;
  A.append(6);
  A.append(6);
  A.append(6);

  LinkedList<int> B;
  B.append(4);
  B.append(3);
  B.append(3);

  LinkedList<int> result = sum(B, A);
  result.print();

  return 0;
}


LinkedList<int> sum(LinkedList<int>& A, LinkedList<int> &B) {
  LinkedList<int> result;

  LinkedList<int> &x = A; // bigger number
  LinkedList<int> &y = B; // smaller number

  if (x.size() < y.size()) {
    LinkedList<int> &temp = x;
    x = y;
    y = temp;
  }

  int numZeros = x.size() - y.size();

  while (numZeros > 0) {
    y.append(0);
    --numZeros;
  }

  LinkedList<int>::Node *node1 = x.kthToLast(x.size());
  LinkedList<int>::Node *node2 = y.kthToLast(y.size());

  bool hasRemainder = false;

  while(node1 != NULL && node2 != NULL) {
    int sum = node1->data + node2->data;
    if (hasRemainder)
      ++sum;

    int remainder = sum%10;
    result.append(remainder);

    hasRemainder = (sum != remainder);
    node1 = node1->next;
    node2 = node2->next;
  }

  if (hasRemainder)
    result.append(1);
  
  return result;
}
