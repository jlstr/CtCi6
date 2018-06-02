#include <iostream>
#include <string>
#include <sstream>
using namespace std;

std::string compressString(const std::string&);

int main() {
  const std::string original = "AAABB";
  cout << original << " COMPRESSED: " << compressString(original) << endl;

  return 0;
}

std::string compressString(const std::string &original) {
  if (original.size() <= 1) {
    return original;
  }

  std::stringstream buffer;
  int count = 1;

  for(std::string::size_type i = 1; i < original.size(); ++i) {
    if (original[i-1] == original[i]) {
      count++;
    } else {
      buffer << original[i-1] << count;
      count = 1;
    }
  }

  buffer << original[original.size()-1] << count;

  if (original.size() < buffer.str().size()) {
    return original;
  }

  return buffer.str();
}
