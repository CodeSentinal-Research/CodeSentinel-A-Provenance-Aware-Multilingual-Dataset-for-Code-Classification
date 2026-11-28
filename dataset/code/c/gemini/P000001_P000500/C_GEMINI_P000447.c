#include <stdio.h>
#define MAX_N 100005
int arr[MAX_N];
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int first = -1, last = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                if (first == -1) first = i;
                last = i;
            }
        }
        printf("%d %d\n", first, last);
    }
    return 0;
}