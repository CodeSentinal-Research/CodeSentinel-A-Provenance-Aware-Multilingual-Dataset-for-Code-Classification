#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Palindrome Linked List */
int main(void) {
    int n;
    long long a[200000];
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) n = 0;
    if (n > 200000) n = 200000;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    int ok = 1;
    for (int i = 0, j = n - 1; i < j; i++, j--) if (a[i] != a[j]) ok = 0;
    printf("%s\n", ok ? "Yes" : "No");


    return 0;
}
