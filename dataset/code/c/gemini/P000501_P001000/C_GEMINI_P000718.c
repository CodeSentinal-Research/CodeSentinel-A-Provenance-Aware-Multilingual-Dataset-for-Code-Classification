#include <stdio.h>
void print_gray(int n, int num) {
    int gray = num ^ (num >> 1);
    for (int i = n - 1; i >= 0; i--) {
        putchar((gray & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            print_gray(n, i);
        }
    }
    return 0;
}