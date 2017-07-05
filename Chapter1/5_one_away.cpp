#include <iostream>
#include <map>
#include <string>
using namespace std;

bool oneAway(const string&, const string&);

int main() {
  string s1 = "pale";
  string s2 = "bae";

  cout << s1 << " and " << s2 << " are one away? " << (oneAway(s1, s2) ? "YES" : "NO") << endl;

  return 0;
}


bool oneAway(const string &A, const string &B) {

  std::map<char, int> chars;

  for (string::size_type i = 0; i < A.size(); ++i) {
    if (chars[A[i]] == 0)
      chars[A[i]] = 1;
    else
      chars[A[i]] = chars[A[i]] + 1;
  }

  for (string::size_type i = 0; i < B.size(); ++i) {
    if (chars[B[i]] == 0)
      chars[B[i]] = 1;
    else
      chars[B[i]] = chars[B[i]] + 1;
  }

  int diffCount = 0;

  for (map<char, int>::const_iterator i = chars.begin(); i != chars.end(); ++i) {
    if (i->second == 1)
      ++diffCount;
  }

  return diffCount == 1 || diffCount == 2;
}
