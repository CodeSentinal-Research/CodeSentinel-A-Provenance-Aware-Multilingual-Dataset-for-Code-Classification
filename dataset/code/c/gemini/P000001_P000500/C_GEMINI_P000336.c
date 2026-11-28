#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(const char* s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

bool check(const char* a, const char* b) {
    int i = 0, j = strlen(a) - 1;
    while (i < j && a[i] == b[j]) {
        i++;
        j--;
    }
    return isPalindrome(a, i, j) || isPalindrome(b, i, j);
}

int main() {
    char a[1005], b[1005];
    if (scanf("%1004s %1004s", a, b) == 2) {
        printf("%s\n", (check(a, b) || check(b, a)) ? "Yes" : "No");
    }
    return 0;
}