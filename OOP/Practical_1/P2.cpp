// Julius Alphonso
// 171105004

/* Write a program to find the size of integer without using sizeof
 */

#include <iostream>

int main() {
  int x=1, size=1;
  while (x!=0) {
    x = x << 1;
    size++;
  }
  std::cout << "sizeof(int) = " << size-1;
}
