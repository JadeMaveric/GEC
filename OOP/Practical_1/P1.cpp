// Julius Alphonso
// 171105004

/* Write a program to print the message "C is a structured programing language"
 * where structured is underlined
 */

#include <iostream>

int main() {
  std::cout << "C is a " << "\e[4m" << "structured" << "\e[0m" << "programing language";
}
