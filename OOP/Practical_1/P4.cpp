// Julius Alphonso
// 171105004

/* Write a program to switch two integers without a temporary variable
 */

#include <iostream>

int main() {
  int a, b;
  cout << "A: " << a << "\n"
       << "B: " << b << "\n"
       << endl;

  a ^= b;
  b ^= a;
  a ^= b;

  cout << "A: " << a << "\n"
       << "B: " << b << "\n"
       << endl;
}
