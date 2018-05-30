#include <string>
#include <iostream>
using namespace std;

bool isUnique(const std::string);

int main() {

  string str = "asno";
  cout << str << " is unique: " << (isUnique(str) ? "YES" : "NO") << endl;

  return 0;
}


bool isUnique(const std::string str) {

  bool uniqueString = true;

  for (std::string::size_type i = 0; i < str.size(); ++i) {
    for (std::string::size_type j = i + 1; j < str.size(); ++j) {
      if (str[i] == str[j]) {
        uniqueString = false;
        break;
      }
    }
  }

  return uniqueString;
}
