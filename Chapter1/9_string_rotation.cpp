#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool checkRotation(const string&, const string&);

int main() {
  string original = "copuer";
  string rotated = "puerco";

  cout << original << " is rotation of " << rotated << "\t" << (checkRotation(original, rotated) ? "YES" : "NO") << endl;

  return 0;
}

// I'm not using the book's solution, this is basically a Brute-force algorithm.
// The book's solution is more efficient, just concatenate s1 with itself, and determine
// if s2 is a substring. ie. s2.isSubstr(s1s1)

bool checkRotation(const string &original, const string &rotated) {
  int count = 1;
  std::stringstream buffer;

  for (string::size_type i = 1; i < original.size(); ++i) {
    buffer << original.substr(i) << original.substr(0, i);

    if (buffer.str() != rotated) {
      ++count;
      buffer.str("");
    } else
      break;
  }

  if (count == static_cast<int>(original.size()))
    return false;

  return true;
}
