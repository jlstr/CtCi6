#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPermutation(std::string&, std::string&);

int main() {
  string s1 = "AASNO";
  string s2 = "SAAON";

  cout << s1 << " is permutation of " << s2 << ": " << (isPermutation(s1, s2) ? "TRUE" : "FALSE") << endl;

  return 0;
}

bool isPermutation(std::string &s1, std::string &s2) {
  if (s1.size() != s2.size()) {
    return false;
  }

  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());

  if (s1 == s2) {
    return true;
  }

  return false;
}
