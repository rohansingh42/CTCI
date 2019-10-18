/* Write a method to replace all spaces in a string with '%20'.
** You may assume that the string has sufficient space at the
** end to hold the additional characters, and that you are
** given the "true" length of the string.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

bool CheckPermutation (std::shared_ptr<std::string> str1,
                       std::shared_ptr<std::string> str2) {
  std::sort(str1->begin(), str1->end());
  std::sort(str2->begin(), str2->end());
  if (str1->size() == str2->size()) {
    for (int i = 0; i < str1->size(); i++) {
      if (str1->at(i) != str2->at(i)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

int main() {
  std::string str1, str2;
  std::cout << "Enter string 1 : ";
  std::cin >> str1;
  std::cout << "Enter string 2 : ";
  std::cin >> str2;
  std::cout << CheckPermutation(
                std::make_shared<std::string>(str1),
                std::make_shared<std::string>(str2))
            << std::endl;
  return 0;
}