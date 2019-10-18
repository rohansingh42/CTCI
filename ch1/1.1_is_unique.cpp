/* Implement an algorithm to determine if
** a string has all unique characters.
** What if you cannot use additional data
** structures?
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

bool CheckUnique (std::shared_ptr<std::string> str) {
  std::sort(str->begin(), str->end());
  for (int i = 0; i < str->size()-1; ++i) {
    if (str->at(i) == str->at(i+1)) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string str;
  std::cout << "Enter string : ";
  std::cin >> str;
  std::cout << CheckUnique(std::make_shared<std::string>(str))
            << std::endl;
  return 0;
}