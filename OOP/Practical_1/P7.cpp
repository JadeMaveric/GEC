// Julius Alphonso
// 171105004

/* Write a program to convert lowercase letters to uppercase
 * using bitwise operators
 */

#include <iostream>

int main() {
  char a[10];
  cin >> a;
  for(i=0; a[i]!='\0';i++)
    a[i] ^= 32;
  cout << a;
}
