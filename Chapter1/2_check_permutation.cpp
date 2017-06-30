#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkPermutation(const std::string, const std::string);

int main() {

  string s1 = "acac";
  string s2 = "caca";

  cout << s1 << " is permutation of " << s2 << ": " << (checkPermutation(s1, s2) ? "YES": "NO") << endl;

  return 0;
}

bool checkPermutation(const std::string A, const std::string B) {
  if (A.size() != B.size())
    return false;

  std::stack<char> chars;
  string bb = B;

  for (string::size_type i = 0; i < A.size(); ++i)
    chars.push(A[i]);

  while (!chars.empty()) {
    char c = chars.top();
    chars.pop();

    string::size_type pos = bb.find(c);
    if (pos == string::npos)
      break;

    bb.erase(pos, 1);
  }

  return bb.size() == 0;
}
