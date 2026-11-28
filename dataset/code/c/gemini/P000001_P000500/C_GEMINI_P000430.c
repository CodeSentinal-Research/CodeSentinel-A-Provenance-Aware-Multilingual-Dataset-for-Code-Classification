#include <stdio.h>
#define MAX_N 100005
int arr[MAX_N];
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == target) { idx = i; break; }
        }
        printf("%d\n", idx);
    }
    return 0;
}