/* Program to implement the following functions recursively and interatively
 * Factorial
 * Fibonacci
 * Sum of Digits
 * Exponentiation
 * GCD
 * LCM
 * Tower of Hanoi
 * String Reverse
 */
 
#include <stdio.h>
#include <string.h>

int print_menu() {
    int i;
    
    printf("1. Factorial\n");
    printf("2. Fibonacci\n");
    printf("3. Sum of Digits\n");
    printf("4. Exponentiation\n");
    printf("5. GCD\n");
    printf("6. LCM\n");
    printf("7. Tower of Hanoi\n");
    printf("8. Reverse String\n");
    printf("0. Exit\n");
    printf(">");
    
    scanf("%d", &i);
    return i;
}

int factorial_recursive(int i) {
    if (i <= 1)
        return 1;
    else
        return i * factorial_recursive(i-1);
}

int factorial_iterative(int i) {
    int fact;
    for (fact=1; i>1; i--)
        fact = fact*i;

    return fact;
}

int fibonacci_recursive(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n) {
    int i, ans, prev, prev_;
    prev  = 1;
    prev_ = 0;
    
    if (n == 0)
        return prev_;
    else if (n == 1)
        return prev;
    else {
        for (i=2; i<=n; i++) {
            ans   = prev + prev_;
            prev_ = prev;
            prev  = ans;
        }
        return ans;
    }
}

int sumOfDigits_recursive(int num) {
    if (num <= 0)
        return 0;
    else
        return num%10 + sumOfDigits_recursive(num/10);
}

int sumOfDigits_iterative(int num) {
    int sum = 0;
    
    while (num > 0) {
        sum += num%10;
        num /= 10;
    }
    
    return sum;
}

int exponent_recursive(int base, int exp) {
    if (exp <= 0)
        return 1;
    else
        return base * exponent_recursive(base, exp-1);
}

int exponent_iterative(int base, int exp) {
    int ans = 1;
    for(; exp>0; exp--)
        ans *= base;
    return ans;
}

int gcd_recursive(int a, int b) {
    if (b==0)
        return a;
    else
        return gcd_recursive(b, a%b);
}

int gcd_iterative(int a, int b) {
    int temp;
    while (b!=0) {
        temp = b;
        b    = a % b;
        a    = temp;
    }
    return a;
}

int _lcm(int lcm, int a, int b) {
    if (lcm%b == 0)
        return lcm;
    else
        return _lcm(lcm+a, a, b);
}

int lcm_recursive(int a, int b) {
    if (a==0 || b==0)
        return 0;
    else
        return _lcm(a, a, b);
}

int lcm_iterative(int a, int b) {
    if (a==0 || b==0)
        return 0;
    else {
        int lcm = a;

        while (lcm%b != 0) {
            lcm += a;
        }
        
        return lcm;
    }
}

void towerOfHanoi_recursive(int n, char src, char temp, char dest) {
    if (n<=1) {
        printf("Move disk from %c to %c\n", src, dest);
        return;
    }
    else
        towerOfHanoi_recursive(n-1, src, dest, temp);
        printf("Move disk from %c to %c\n", src, dest);
        towerOfHanoi_recursive(n-1, temp, src, dest);
}

void reverseString_recursive(char * str, int length) {
    if (length <= 1)
        return;
    else
        str[0] ^= str[length-1];
        str[length-1] ^= str[0];
        str[0] ^= str[length-1];
        
        reverseString_recursive(++str, length-2);
}

void reverseString_iterative(char * str, int length) {
    int i;
    for (i=0; i<length; i++) {
        int k = length - 1 - i;
        if (i>=k)
            break;
        str[i] ^= str[k];
        str[k] ^= str[i];
        str[i] ^= str[k];
    }
}

int main() {
    int i, j;
    char str[20];
    
    printf("1. Iterative\n2. Recursive\n>");
    scanf("%d", &i);
    
    if (i == 1) {
        i = print_menu();
        switch (i) {
            case 1:
                printf("Enter number to find factorial of: ");
                scanf("%d", &i);
                i = factorial_iterative(i);
                printf("%d\n", i);
                break;
            case 2:
                printf("Enter which term you want: ");
                scanf("%d", &i);
                i = fibonacci_iterative(i);
                printf("%d\n", i);
                break;
            case 3:
                printf("Enter number: ");
                scanf("%d", &i);
                i = sumOfDigits_iterative(i);
                printf("Sum of Digits = %d\n", i);
                break;
            case 4:
                printf("Enter base: ");
                scanf("%d", &i);
                printf("Enter power: ");
                scanf("%d", &j);
                i = exponent_iterative(i, j);
                printf("%d\n", i);
                break;
            case 5:
                printf("Enter num1: ");
                scanf("%d", &i);
                printf("Enter num2: ");
                scanf("%d", &j);
                i = gcd_iterative(i, j);
                printf("%d\n", i);
                break;
            case 6:
                printf("Enter num1: ");
                scanf("%d", &i);
                printf("Enter num2: ");
                scanf("%d", &j);
                i = lcm_iterative(i, j);
                printf("%d\n", i);
                break;
            case 7:
                printf("Enter number of disks: ");
                scanf("%d", &i);
                towerOfHanoi_recursive(i, 'A', 'B', 'C');
                break;
            case 8:
                printf("Enter string: ");
                scanf("%s", str);
                for(j=0; str[j]!='\0'; j++);
                reverseString_iterative(str, j);
                printf("%s\n", str);
                break;
        }
    }
    else if (i == 2) {
        retry:
        i = print_menu();
        switch (i) {
            case 1:
                printf("Enter number to find factorial of: ");
                scanf("%d", &i);
                i = factorial_recursive(i);
                printf("%d\n", i);
                break;
            case 2:
                printf("Enter which term you want: ");
                scanf("%d", &i);
                i = fibonacci_recursive(i);
                printf("%d\n", i);
                break;
            case 3:
                printf("Enter number: ");
                scanf("%d", &i);
                i = sumOfDigits_recursive(i);
                printf("Sum of Digits = %d\n", i);
                break;
            case 4:
                printf("Enter base: ");
                scanf("%d", &i);
                printf("Enter power: ");
                scanf("%d", &j);
                i = exponent_recursive(i, j);
                printf("%d\n", i);
                break;
            case 5:
                printf("Enter num1: ");
                scanf("%d", &i);
                printf("Enter num2: ");
                scanf("%d", &j);
                i = gcd_recursive(i, j);
                printf("%d\n", i);
                break;
            case 6:
                printf("Enter num1: ");
                scanf("%d", &i);
                printf("Enter num2: ");
                scanf("%d", &j);
                i = lcm_recursive(i, j);
                printf("%d\n", i);
                break;
            case 7:
                printf("Enter number of disks: ");
                scanf("%d", &i);
                towerOfHanoi_recursive(i, 'A', 'B', 'C');
                break;
            case 8:
                printf("Enter string: ");
                scanf("%s", str);
                for(j=0; str[j]!='\0'; j++);
                reverseString_recursive(str, j);
                printf("%s\n", str);
                break;
            default:
                goto retry;
        }
    }
    
    return 0;
}

