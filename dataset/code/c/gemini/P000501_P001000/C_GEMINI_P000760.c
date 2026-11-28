#include <stdio.h>
char cur[32];
void inc_numbers(int n, int start, int len) {
    if (len == n) {
        cur[len] = '\0';
        printf("%s\n", cur);
        return;
    }
    for (int d = start; d <= 9; d++) {
        cur[len] = '0' + d;
        inc_numbers(n, d + 1, len + 1);
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 1) printf("0\n");
        inc_numbers(n, 1, 0);
    }
    return 0;
}