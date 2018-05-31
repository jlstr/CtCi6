#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

std::string URLify(const std::string&);

int main() {
  const std::string str = "Living in Münich is the Answer";
  cout << URLify(str) << endl;

  return 0;
}

std::string URLify(const std::string &str) {
  std::stringstream buffer;

  for(std::string::size_type i = 0; i < str.size(); ++i) {
    if (str[i] == ' ') {
      buffer << "%20";
    } else {
      buffer << str[i];
    }
  }

  return buffer.str();
}
