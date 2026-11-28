#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int arr[100005];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int x;
        scanf("%d", &x);
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) { idx = i; break; }
        }
        printf("%d\n", idx);
    }
    return 0;
}