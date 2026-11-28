#include <string.h>
#include <stdbool.h>

bool isPaliC(char* s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

bool validPalindrome(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return isPaliC(s, i + 1, j) || isPaliC(s, i, j - 1);
        }
        i++; j--;
    }
    return true;
}