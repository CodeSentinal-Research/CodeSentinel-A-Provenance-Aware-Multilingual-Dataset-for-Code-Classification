#include <stdio.h>

int n, k;
int a[10];
int mx = 1000000000;

void gen(int i, int *ch) {
    if (i == n) {
        int mx_v = 0;
        for (int j = 0; j < k; j++) {
            if (ch[j] > mx_v) mx_v = ch[j];
        }
        if (mx_v < mx) mx = mx_v;
        return;
    }
    for (int j = 0; j < k; j++) {
        ch[j] += a[i];
        gen(i + 1, ch);
        ch[j] -= a[i];
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ch[10] = {0};
    gen(0, ch);
    printf("%d\n", mx);
    return 0;
}
