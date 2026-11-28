#include <stdbool.h>

bool isPalindrome(int n) {
    if (n < 0) return false;
    long long original = n, rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return original == rev;
}
