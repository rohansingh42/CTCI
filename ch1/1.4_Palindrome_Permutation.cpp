/* Given a string, write a function to check if it is a permutation
 * of a palindrome. A palindrome is a word or phrase that is the
 * same forwards and backwards. A permutation is a rearrangement
 * of letters. The palindrome does not need to be limited to just
 * dictionary words.
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

bool CheckPalindromePerm (std::string str) {
  std::vector<int> cnt(256,0);
  for (auto c : str) {
    cnt[static_cast<int>(c)] = (cnt[static_cast<int>(c)] + 1) % 2;
  }
  bool f = false;
  for (auto i : cnt) {
    if (i == 1 && (str.size() % 2) == 1) {
      if (f == false) {
        f = true;
      } else {
        return false;
      }
    } else if (i == 1 && (str.size() % 2) == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  std::string str;
  std::cout << "Enter string : ";
  std::cin >> str;
  std::cout << CheckPalindromePerm(str)
            << std::endl;
  return 0;
}