// Julius Alphonso
// 171105004

/* Write a program to generate the first 10 terms of the sequence
 * <1 -3 6 -10 15 -21>
 */

#include <iostream>

int main() {
  int num = 1;
  for (int i=0; i<10; i++) {
    a = a+i;
    cout << (i%2?a:-a) << " ";
  }
}
