#include <iostream>
#include "convert.hpp"

int main(void) {
  std::cout << conv::bin_to_ascii("01001111 01101011") << '\n';
  std::cout << conv::ascii_to_bin("Ok") << '\n';
  std::cout << conv::bin_to_hex("01001111 01101011") << '\n';
  std::cout << conv::ascii_to_hex("Ok") << '\n';
  return 0;
}
