#include <stdio.h>
#include <stdbool.h>
bool used[32];
int backtrack(int pos, int n) {
    if (pos > n) return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && (i % pos == 0 || pos % i == 0)) {
            used[i] = true;
            count += backtrack(pos + 1, n);
            used[i] = false;
        }
    }
    return count;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%d\n", backtrack(1, n));
    }
    return 0;
}