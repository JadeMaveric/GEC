// Julius Alphonso
// 171105004

/* Write an efficient program to print out the factorial of a number
 * between 1 and 10
 */

#include <iostream>

int main() {
  int x;
  int fact[] = {
    1,
    1,
    1*2,
    1*2*3,
    1*2*3*4,
    1*2*3*4*5,
    1*2*3*4*5*6,
    1*2*3*4*5*6*7,
    1*2*3*4*5*6*7*8,
    1*2*3*4*5*6*7*8*9,
    1*2*3*4*5*6*7*8*9*10
  };
  std::cout << "Enter a number [1-10]: ";
  std::cin >> x;
  std::cout << x%11 << "! = " << fact[x%11] << endl;
}
